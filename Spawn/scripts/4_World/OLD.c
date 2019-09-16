/* 	void SaveInventory()
	{
		SavePlayer					m_SavePlayer 				= new SavePlayer();
		array< EntityAI >			m_EnumeratedInventory		= new array< EntityAI >();
		array< ref SaveObject >		m_SaveObjects				= new array< ref SaveObject >();
		array< ref SaveObject >		m_RootChildren			= new array< ref SaveObject >();
		EntityAI					m_Root;
		SaveObject					m_ParentObject;

		GetHumanInventory().EnumerateInventory( InventoryTraversalType.PREORDER, m_EnumeratedInventory );

		for ( int i = ( m_EnumeratedInventory.Count() - 1 ); i > -1; i-- )
		{
			EntityAI		localEntity 	= m_EnumeratedInventory[i];
			EntityAI		localParent 	= localEntity.GetHierarchyParent();
			ItemBase		localItem		= ItemBase.Cast( m_EnumeratedInventory[i] );
			SurvivorBase	localPlayer;
			SaveObject 		tempObject;

			if ( !m_Root )
			{
				m_Root = localParent;
			}

			if ( m_Root != localEntity && Class.CastTo( localPlayer, localParent ) )
			{
				tempObject = new SaveObject();
				tempObject.SetType( localEntity.GetType() );
				tempObject.SetChildren( m_RootChildren );

				m_RootChildren = new array< ref SaveObject >();
				m_SaveObjects.Insert( tempObject );
				m_Root = null;
			}
			else if ( m_Root == localEntity && Class.CastTo( localPlayer, localParent ) )
			{
				tempObject = new SaveObject();
				tempObject.SetType( localEntity.GetType() );
				tempObject.SetChildren( m_RootChildren );

				m_RootChildren = new array< ref SaveObject >();
				m_SaveObjects.Insert( tempObject );
				m_Root = null;
			}
			else if ( m_Root == localEntity && !Class.CastTo( localPlayer, localParent ) )
			{
				tempObject = new SaveObject();
				tempObject.SetType( localEntity.GetType() );
				tempObject.SetChildren( m_RootChildren );

				m_RootChildren = new array< ref SaveObject >();
				m_RootChildren.Insert( tempObject );
				m_Root = localParent;
			}
			else if ( m_Root != localEntity )
			{
				tempObject = new SaveObject();
				tempObject.SetType( localEntity.GetType() );

				m_RootChildren.Insert( tempObject );
			}
		}

		m_SaveObjects.Debug();

		m_SavePlayer.SetPos( GetPosition() );
		m_SavePlayer.SetInventory( m_SaveObjects );

		string playerDir = m_ModDir + "\\" + GetIdentity().GetPlainId() ;
		if ( !FileExist( playerDir ) )
			MakeDirectory( playerDir );

		JsonFileLoader< ref SavePlayer >.JsonSaveFile( playerDir + m_StrCiv, m_SavePlayer );
	} */

/* void SaveInventory()
	{
		ref SavePlayer					savePlayer				= new SavePlayer();
		ref array< EntityAI > 			enumeratedInventory 	= new array< EntityAI >();
		ref array< ref SaveObject > 	saveObjects 			= new array< ref SaveObject >();

		GetHumanInventory().EnumerateInventory( InventoryTraversalType.PREORDER, enumeratedInventory );
		bool isNCC = false;

		ItemBase		m_PlayerEntity;
		ItemBase		m_Root;
		ItemBase		m_NestedEntity;
		SaveObject 		m_ClothingObject;
		SaveObject 		m_ParentObject;
		SaveObject 		m_NestedObject;
					
		for ( int i = 0; i < enumeratedInventory.Count(); i++ )
		{
			ItemBase 		entity = ItemBase.Cast( enumeratedInventory[i] );

			Print("WHAT THE FUCK | " + entity.GetQuantity() );
			Man				tempPlayer;
			
			if ( !entity ) return;

			if ( Class.CastTo( tempPlayer, entity.GetHierarchyParent() ) )
			{
				m_PlayerEntity = entity;
				m_ClothingObject = new SaveObject();
				m_ClothingObject.SetType( entity.GetType() );
				m_ClothingObject.SetQuantity( entity.GetQuantity() );
				if ( entity == GetHumanInventory().GetEntityInHands() )
					m_ClothingObject.IsInHands();

				saveObjects.Insert( m_ClothingObject );
			}
			else if ( m_PlayerEntity && entity.GetHierarchyParent() == m_PlayerEntity )
			{
				m_Root = entity;
				m_ParentObject = new SaveObject();
				m_ParentObject.SetType( entity.GetType() );
				m_ParentObject.SetQuantity( entity.GetQuantity() );
				
				m_ClothingObject.AddChild( m_ParentObject );
			}
			else if ( m_PlayerEntity && m_Root && entity.GetHierarchyParent() == m_Root )
			{
				m_NestedEntity = entity;
				m_NestedObject = new SaveObject();
				m_NestedObject.SetType( entity.GetType() );
				m_NestedObject.SetQuantity( entity.GetQuantity() );

				m_ParentObject.AddChild( m_NestedObject );
			}
			else if ( m_PlayerEntity && m_Root && m_NestedObject && entity.GetHierarchyParent() == m_NestedEntity )
			{
				SaveObject tempObject = new SaveObject();
				tempObject.SetType( entity.GetType() )
				tempObject.SetQuantity( entity.GetQuantity() );
				
				m_NestedObject.AddChild( tempObject );
			}
		}

		savePlayer.SetPos( GetPosition() );
		savePlayer.SetInventory( saveObjects );

		if ( isNCC )
		{

		}
		else
		{
			string playerDir = m_ModDir + "\\" + GetIdentity().GetPlainId() ;
			if ( !FileExist( playerDir ) )
				MakeDirectory( playerDir );

			JsonFileLoader< ref SavePlayer >.JsonSaveFile( playerDir + m_StrCiv, savePlayer );
 			m_FileSerializer.Open( playerDir + m_StrCiv, FileMode.WRITE );
			m_FileSerializer.Write( saveObjects );
		}
	}*/