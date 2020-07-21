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
};