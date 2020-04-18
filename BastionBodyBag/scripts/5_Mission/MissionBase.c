modded class MissionServer {	
	void CreateConfigObject( string type, vector pos, vector dir )
	{
		auto obj = GetGame().CreateObject( type, pos );
		obj.SetPosition( pos );
		obj.SetOrientation( dir );
		obj.SetOrientation( obj.GetOrientation() );
		obj.Update();
		obj.SetAffectPathgraph( true, false );
		if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
	}

    void MissionServer() {
        if ( GetGame().IsServer() )
        {
            array<ref ConfigObject> objects = new array<ref ConfigObject>;

            if ( !FileExist( BastionBodyBagConst.baseDir ) )
            {
                MakeDirectory( BastionBodyBagConst.baseDir );
            }

            if ( FileExist( BastionBodyBagConst.config ) )
            {
                JsonFileLoader<array<ref ConfigObject>>.JsonLoadFile( BastionBodyBagConst.config, objects );
            }
            else
            {
                objects.Insert( new ConfigObject("4963.054199 10.000120 4313.844238", "69.0 0.0 0.0") );
                JsonFileLoader<array<ref ConfigObject>>.JsonSaveFile( BastionBodyBagConst.config, objects );
            }

            foreach( auto object : objects )
            {
				CreateConfigObject( "BST_Compactor", object.GetPosition(), object.GetDirection() );
            }
        }
    }
}