typedef Param1< BRP_RemoteIED > bombParam;

class BRP_RemoteDetonator : ItemBase
{
	protected static ref JsonSerializer 	m_Serializer 	= new JsonSerializer;
	ref array< ref BRP_RemoteIED > 				m_Bombs;
	ref array< ref vector >					m_BombVectors;
	string									jsonString;
	string									error;

	void BRP_RemoteDetonator()
	{
		m_Bombs 		= new array< ref BRP_RemoteIED >;
		m_BombVectors 	= new array< ref vector >;
	}

	override void OnStoreSave( ParamsWriteContext ctx )
	{
		super.OnStoreSave( ctx );

		BuildVectorArray();
		m_BombVectors.Debug();
		m_Serializer.WriteToString( m_BombVectors, false, jsonString );
		ctx.Write( jsonString );
	}

	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad(ctx, version) )
			return false;

		if ( !ctx.Read( jsonString ) )
			return false;

		return true;
	}

	override void AfterStoreLoad()
	{
		if ( !GetGame().IsServer() ) return;

		if ( jsonString != "" )
		{
			m_Serializer.ReadFromString( m_BombVectors, jsonString, error );
			BuildBombArray();
			SendToClient();
		}
	}

	void BuildVectorArray()
	{
		m_BombVectors = new array< ref vector >;
		for ( int i = 0; i < m_Bombs.Count(); i++ )
		{
			vector IEDPos = m_Bombs.Get(i).GetPosition();

			if ( !IEDPos)
			{
				Print("[DEBUG] IEDPos not found!!");
				continue;
			}

			m_BombVectors.Insert( IEDPos );
		}
		Print("[DEBUG] BUILDVECTORARRAY");
		m_BombVectors.Debug();
	}

	void BuildBombArray()
	{
		for ( int i = 0; i < m_BombVectors.Count(); i++ )
		{
			array<Object> 		objects 	= new array<Object>;
			array<CargoBase> 	cargo 		= new array<CargoBase>;
			vector				pos			= m_BombVectors.Get(i);

			GetGame().GetObjectsAtPosition( pos, 0.1, objects, cargo );
			Print("[DEBUG] [BUILDBOMBARRAY] objects array debug");
			objects.Debug();
			for ( int j = 0; j < objects.Count(); j++ )
			{
				BRP_RemoteIED IED = BRP_RemoteIED.Cast( objects.Get(j) );

				if ( IED )
				{
					Print("[DEBUG] [BUILDBOMBARRAY] IED Found, inserting ");
					m_Bombs.Insert( IED );
				}
			}
		}
		Print("[DEBUG] [BUILDBOMBARRAY] bomb vectors array debug");
		m_Bombs.Debug();
	}
	
	void SendToClient()
	{
		PlayerBase player = GetHierarchyRootPlayer();
		for ( int i = 0; i < m_Bombs.Count(); i++ )
		{
			BRP_RemoteIED IED = m_Bombs.Get(i);
			bombParam data = new bombParam( IED );
			GetGame().RPCSingleParam( this, 998911108, data, true, player.GetIdentity() )
		}
	}

	ref array< ref BRP_RemoteIED > GetBombsInRange( PlayerBase player )
	{
		int inRange = 0;
		ref array< ref BRP_RemoteIED > tempArray = new array< ref BRP_RemoteIED >;

		for ( int i = 0; i < m_Bombs.Count(); i++ )
		{
			BRP_RemoteIED IED = m_Bombs.Get(i);
			if ( vector.Distance( IED.GetPosition(), player.GetPosition() ) < 300 )
				tempArray.Insert( IED );
		}

		return tempArray;
	}

	bool HasBomb( BRP_RemoteIED IED )
	{
		//Print("[RS][DEBUG] Checking detonator for m_Bombs!");
		for ( int i = 0; i < m_Bombs.Count(); i++ )
		{
			BRP_RemoteIED localIED = m_Bombs.Get(i);

			if ( !localIED ) break;
			if ( IED == localIED )
			{
				Print("[RS][DEBUG] Bomb found!");
				return true;
			}
		}
		return false;
	}

	void AddBomb( BRP_RemoteIED IED )
	{
		Print("[RS][DEBUG] Adding bomb to detonator!");
		if ( HasBomb( IED ) )
		{
			Print("[RS][DEBUG] Detonator already has bomb!");
			return;
		}

		m_Bombs.Insert( IED );
		Print("[RS][DEBUG] Added bomb to detonator!");
	}

	void DetonateBombsInRange( ref array< ref BRP_RemoteIED > bombsToDetonate )
	{
		Print("[RS][DEBUG] Detonating all m_Bombs on detonator! " + bombsToDetonate.Count() );
		for ( int i = 0; i < bombsToDetonate.Count(); i++ )
		{
			Print("[RS][DEBUG] Detonating bomb!");
			BRP_RemoteIED bombToDetonate = bombsToDetonate.Get(i);
			for ( int j = 0; j < m_Bombs.Count(); j++ )
			{
				BRP_RemoteIED localIED = m_Bombs.Get(j);

				if ( !localIED )
				{
					m_Bombs.Remove(j);
					continue;
				}

				if ( localIED == bombToDetonate )
				{
					Print("[RS][DEBUG] Detonated bomb=" + bombToDetonate );
					m_Bombs.Remove(j);

					if ( GetGame().IsServer() )
					{
						if ( bombToDetonate.IsDisarmed() ) continue;

						bombToDetonate.Explode(DT_EXPLOSION);
						GetGame().ObjectDelete( bombToDetonate );
					}
				}
			}
		}
	}

	override void OnRPC( PlayerIdentity sender, int rpc_type, ParamsReadContext ctx ) 
	{
		super.OnRPC(sender, rpc_type,ctx);

		if ( GetGame().IsClient() )
		{
			if ( rpc_type == 998911108 )
			{
				bombParam data;
				ctx.Read( data );
				
				BRP_RemoteIED IED = data.param1;
				if ( IED )
					m_Bombs.Insert( IED );
			}
		}
	}
	
	override void SetActions()
	{
		super.SetActions()
		
		AddAction( ActionTouchOffIED );
	}
}