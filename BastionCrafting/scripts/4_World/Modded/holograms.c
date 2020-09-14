modded class Hologram
{
	override void UpdateHologram( float timeslice )
	{
		super.UpdateHologram(timeslice);
		ItemBase container = m_Parent;
		if(container){
			vector containerPos = GetProjectionEntityPosition( m_Player ) + container.Get_ItemPlacingPos();
			vector containerOrientation = AlignProjectionOnTerrain( timeslice ) + container.Get_ItemPlacingOrientation();
			SetProjectionPosition( containerPos );
			SetProjectionOrientation( containerOrientation );		
			m_Projection.OnHologramBeingPlaced( m_Player );
			return;
		}
	}
	
	EntityAI PlaceEntity( EntityAI entity_for_placing )
	{
		if ( entity_for_placing.IsInherited( BRP_Kit ))
		{
			return entity_for_placing;
		}
		
		//From Base Storage
        ItemBase item_in_hands = ItemBase.Cast( m_Player.GetHumanInventory().GetEntityInHands() );
		if ( item_in_hands && item_in_hands.CanMakeGardenplot() )
        {
            Class.CastTo(entity_for_placing, GetGame().CreateObject( m_Projection.GetType(), m_Projection.GetPosition() ));
        }
            
        if( entity_for_placing.CanAffectPathgraph() )
        {        
            entity_for_placing.SetAffectPathgraph( true, false );
            
            GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(GetGame().UpdatePathgraphRegionByObject, 100, false, entity_for_placing);
        }
		return super.PlaceEntity(entity_for_placing);
	}

	override string GetProjectionName(ItemBase item)
	{
		BRP_Kit item_in_hands = BRP_Kit.Cast( item );
		if ( item_in_hands )
			return item_in_hands.Get_ItemName();
		
		return super.GetProjectionName(item);
	}

	override void EvaluateCollision(ItemBase action_item = null)
	{			
		ItemBase item_in_hands = m_Parent;

		if ( item_in_hands.IsInherited(BRP_Kit))
		{
			SetIsColliding(false);
			return;
		}
		
		//From Base Storage
		ItemBase m_Projection = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		ItemBase fortfloor = FadedCollision();
		
        if ( m_Projection.IsInherited(Base_Almara_Kit) || m_Projection.IsInherited(Base_Almara_Large_Kit) || m_Projection.IsInherited(Base_GMetalCrate_Kit) || m_Projection.IsInherited(Base_BMetalCrate_Kit) || m_Projection.IsInherited(Base_Cot_Kit) || m_Projection.IsInherited(Base_Nightstand_Kit) || m_Projection.IsInherited(Base_Chernarus_Flag_Kit) || m_Projection.IsInherited(Base_CornerSofa_Kit) || m_Projection.IsInherited(Base_LeatherSofa_Kit) || m_Projection.IsInherited(Base_WoodStorage_Kit) || m_Projection.IsInherited(Base_SingleBed_Kit) || m_Projection.IsInherited(Base_CoffeeTable_Kit))
        {
            SetIsColliding(false);
            return;
        }
		return;
		super.EvaluateCollision();
	}

		
	override void RefreshVisual()
	{
		if ( m_Projection && m_Projection.IsKindOf("BRP_Item"))
		{
			string config_material = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterial";
			string hologram_material = GetGame().ConfigGetTextOut( config_material );
			string config_model = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hologramMaterialPath";
			string hologram_material_path = GetGame().ConfigGetTextOut( config_model ) + "\\" + hologram_material;
			string selection_to_refresh;
			int hidden_selection = 0;
			static const string textureName = "#(argb,8,8,3)color(0.5,0.5,0.5,0.75,ca)";
			
			string config_path = "CfgVehicles" + " " + m_Projection.GetType() + " " + "hiddenSelections";
			ref array<string> hidden_selection_array = new array<string>;

			GetGame().ConfigGetTextArray( config_path, hidden_selection_array );	
			hologram_material_path += CorrectMaterialPathName();
				
			for (int i = 0; i < hidden_selection_array.Count(); ++i)
			{
				selection_to_refresh = hidden_selection_array.Get(i);
				hidden_selection = GetHiddenSelection( selection_to_refresh );
				m_Projection.SetObjectTexture( hidden_selection, textureName );
				m_Projection.SetObjectMaterial( hidden_selection, hologram_material_path );
			}
		}
		else
		{
			super.RefreshVisual();
		}
		
	}

	override bool IsFloating() 
	{
		if (m_Parent.IsInherited(BRP_Kit))
			return true;
		
		return super.IsFloating();
	}

	override void SetProjectionPosition( vector position )
	{	
		if (m_Parent.IsInherited(BRP_Kit) && IsFloating())
		{ 
			vector itemPos = SetOnGround( position ) + m_Parent.Get_ItemPlacingPos();
			m_Projection.SetPosition( itemPos );
			return;
		}

		super.SetProjectionPosition(position);
	}
	
	
	//Base Storage
	ItemBase FadedCollision()
	{
		vector center;
		vector relative_ofset;
		vector absolute_ofset = "0 0.01 0"; 
		vector orientation = GetProjectionOrientation();
		vector edge_length;
		vector min_max[2];
		ref array<Object> excluded_objects = new array<Object>;
		ref array<Object> collided_objects = new array<Object>;
		
		m_Projection.GetCollisionBox( min_max );
		relative_ofset[1] = ( min_max[1][1] - min_max[0][1] ) / 2.4;
		center = m_Projection.GetPosition() + relative_ofset + absolute_ofset;
		edge_length = GetCollisionBoxSize( min_max );
		excluded_objects.Insert( m_Projection );

		if ( GetGame().IsBoxColliding( center, orientation, edge_length, excluded_objects, collided_objects ) )
		{	
			for( int i = 0; i < collided_objects.Count(); i++ )
			{
				Object obj_collided = collided_objects[i];
				if( obj_collided.IsInherited(Base_Almara) )
				{
					Base_Almara base_almara = Base_Almara.Cast(obj_collided);
					return base_almara;
				}
				if( obj_collided.IsInherited(Base_Almara_Large) )
				{
					Base_Almara_Large base_almara_large = Base_Almara_Large.Cast(obj_collided);
					return base_almara_large;
				}
				if( obj_collided.IsInherited(Base_GMetalCrate) )
				{
					Base_GMetalCrate base_gmetalcrate = Base_GMetalCrate.Cast(obj_collided);
					return base_gmetalcrate;
				}
				if( obj_collided.IsInherited(Base_BMetalCrate) )
				{
					Base_BMetalCrate base_bmetalcrate = Base_BMetalCrate.Cast(obj_collided);
					return base_bmetalcrate;
				}
				if( obj_collided.IsInherited(Base_Cot) )
				{
					Base_Cot base_cot = Base_Cot.Cast(obj_collided);
					return base_cot;
				}
				if( obj_collided.IsInherited(Base_Nightstand) )
				{
					Base_Nightstand base_nightstand = Base_Nightstand.Cast(obj_collided);
					return base_nightstand;
				}
				if( obj_collided.IsInherited(Base_Chernarus_Flag) )
				{
					Base_Chernarus_Flag base_chernarus_flag = Base_Chernarus_Flag.Cast(obj_collided);
					return base_chernarus_flag;
				}
				if( obj_collided.IsInherited(Base_CornerSofa) )
				{
					Base_CornerSofa base_cornersofa = Base_CornerSofa.Cast(obj_collided);
					return base_cornersofa;
				}
				if( obj_collided.IsInherited(Base_LeatherSofa) )
				{
					Base_LeatherSofa base_leathersofa = Base_LeatherSofa.Cast(obj_collided);
					return base_leathersofa;
				}
				if( obj_collided.IsInherited(Base_WoodStorage) )
				{
					Base_WoodStorage base_woodstorage = Base_WoodStorage.Cast(obj_collided);
					return base_woodstorage;
				}
				if( obj_collided.IsInherited(Base_SingleBed) )
				{
					Base_SingleBed base_singlebed = Base_SingleBed.Cast(obj_collided);
					return base_singlebed;
				}
				if( obj_collided.IsInherited(Base_CoffeeTable) )
				{
					Base_CoffeeTable base_coffeetable = Base_CoffeeTable.Cast(obj_collided);
					return base_coffeetable;
				}
			}
		}
		return null;
	}
	
	override string ProjectionBasedOnParent()
	{
		ItemBase item_in_hands = ItemBase.Cast(m_Player.GetHumanInventory().GetEntityInHands());
		
		if (item_in_hands.IsInherited(Base_Almara_Kit))
			return "Base_Almara";
		if (item_in_hands.IsInherited(Base_Almara_Large_Kit))
			return "Base_Almara_Large";
		if (item_in_hands.IsInherited(Base_GMetalCrate_Kit))
			return "Base_GMetalCrate";
		if (item_in_hands.IsInherited(Base_BMetalCrate_Kit))
			return "Base_BMetalCrate";
		if (item_in_hands.IsInherited(Base_Cot_Kit))
			return "Base_Cot";
		if (item_in_hands.IsInherited(Base_Nightstand_Kit))
			return "Base_Nightstand";
		if (item_in_hands.IsInherited(Base_Chernarus_Flag_Kit))
			return "Base_Chernarus_Flag";
		if (item_in_hands.IsInherited(Base_CornerSofa_Kit))
			return "Base_CornerSofa";
		if (item_in_hands.IsInherited(Base_LeatherSofa_Kit))
			return "Base_LeatherSofa";
		if (item_in_hands.IsInherited(Base_WoodStorage_Kit))
			return "Base_WoodStorage";
		if (item_in_hands.IsInherited(Base_SingleBed_Kit))
			return "Base_SingleBed";
		if (item_in_hands.IsInherited(Base_CoffeeTable_Kit))
			return "Base_CoffeeTable";

		return super.ProjectionBasedOnParent();
	}
	
	
};