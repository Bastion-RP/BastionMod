modded class VicinityContainer: CollapsibleContainer
{
	override void UpdateInterval()
	{
		PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
		
		if(!player)
			return;
		
		EntityAI eai;
		vector pos = player.GetPosition();
		ref array<EntityAI> objects;
		
		VicinityItemManager.GetInstance().Update( player.GetDeltaT() );
		objects = VicinityItemManager.GetInstance().GetVicinityItems();
		
		//GetItemsShowableInInventory
		array<EntityAI> showable_items = new array<EntityAI>;
		int m_OldShowedItemIconsCount = m_ShowedItemIcons.Count();
		m_ShowedItemIcons.Clear();
		
		GameInventory game_inventory = player.GetInventory();
		for( int i = 0; i < objects.Count(); i++ )
		{
			eai = objects.Get( i );			
			if ( eai == null || game_inventory.IsPlaceholderEntity( eai ) )
				continue; // noproxy: ignore body placeholder

			if( eai.IsInventoryVisible() )
			{
				showable_items.Insert( eai );

				if( !eai.IsInherited( DayZInfected ) && !eai.IsInherited( PlayerBase ) && !eai.IsInherited( AnimalBase ) && !eai.DisableVicinityIcon() )
				{
					m_ShowedItemIcons.Insert( eai );
				}
			}
		}

		ref map<EntityAI, ref Container> new_showed_items = new ref map<EntityAI, ref Container>;
		ref map<int, ref Container> showed_items_IDs = new ref map<int, ref Container>;
		for ( i = 0; i < showable_items.Count(); i++ )
		{
			EntityAI entity = showable_items.Get( i );
			if( entity )
			{
				if( game_inventory && !m_ShowedItems.Contains( entity ) )
				{
					string config = "CfgVehicles " + entity.GetType() + " GUIInventoryAttachmentsProps";

					if( GetGame().ConfigIsExisting( config ) )
					{
						AttachmentCategoriesContainer ac = new AttachmentCategoriesContainer( m_Parent, -1 );
						ac.SetEntity( entity );
						new_showed_items.Insert( entity, ac );
						showed_items_IDs.Insert( entity.GetID(), ac);
					}
					else if ( entity.GetSlotsCountCorrect() > 0 && entity.GetInventory().GetCargo() )
					{
						if( entity.IsInherited( DayZInfected ) )
						{
							if( entity.IsAlive() )
							{
								continue;
							}
							ZombieContainer zmb_cnt = new ZombieContainer( m_Parent, -1 );
							zmb_cnt.SetEntity( entity );
							new_showed_items.Insert( entity, zmb_cnt );
							showed_items_IDs.Insert( entity.GetID(), zmb_cnt );
							Container.Cast( GetParent() ).Insert( zmb_cnt );
						}
						else
						{
							ContainerWithCargoAndAttachments iwca = new ContainerWithCargoAndAttachments( this, -1 );
							iwca.SetEntity( entity );
							new_showed_items.Insert( entity, iwca );
							showed_items_IDs.Insert( entity.GetID(), iwca );
						}
					}
					else if( entity.GetInventory().GetCargo() )
					{
						ContainerWithCargo iwc = new ContainerWithCargo( this, -1 );
						iwc.SetEntity( entity, 0 );
						new_showed_items.Insert( entity, iwc );
						showed_items_IDs.Insert( entity.GetID(), iwc );
						iwc.UpdateInterval();
					}
					else if( entity.GetSlotsCountCorrect() > 0 )
					{
						if( entity.HasEnergyManager() )
						{
							ContainerWithElectricManager iwem = new ContainerWithElectricManager( this, -1 );
							iwem.SetEntity( entity );
							new_showed_items.Insert( entity, iwem );
							showed_items_IDs.Insert( entity.GetID(), iwem );
						}
						else
						{
							if ( entity.IsInherited( PlayerBase ) )
							{
								if( entity.IsAlive() && ( !PlayerBase.Cast( entity ).IsUnconscious() && !PlayerBase.Cast( entity ).IsRestrained()  && !PlayerBase.Cast( entity ).HasHandsUp() ) )
								{
									continue;
								}
								
								PlayerContainer plyr_cnt = new PlayerContainer( m_Parent );
								plyr_cnt.SetPlayer( PlayerBase.Cast( entity ) );
								Container.Cast( GetParent() ).Insert( plyr_cnt );
								( Container.Cast( m_Parent ) ).Refresh();
								new_showed_items.Insert( entity, plyr_cnt );
								showed_items_IDs.Insert( entity.GetID(), plyr_cnt);
							}
							else
							{
								ContainerWithCargoAndAttachments iwcas = new ContainerWithCargoAndAttachments( this, -1 );
								iwcas.SetEntity( entity );
								new_showed_items.Insert( entity, iwcas );
								showed_items_IDs.Insert( entity.GetID(), iwcas );
							}
						}
					}
				}
				else
				{
					if( m_ShowedItems.Get( entity ) )
					{
						if ( entity.IsInherited( PlayerBase ) )
						{
							if( entity.IsAlive() && ( !PlayerBase.Cast( entity ).IsUnconscious() && !PlayerBase.Cast( entity ).IsRestrained() && !PlayerBase.Cast( entity ).HasHandsUp() ) )  //Why doesnt IsSurrendered work here, some lame sync shit
							{
								continue;
							}
						}
						new_showed_items.Insert( entity, m_ShowedItems.Get( entity ) );
						showed_items_IDs.Insert( entity.GetID(), m_ShowedItemsIDs.Get( entity.GetID() ) );
					}
				}
			}
		}
		
		ref map<CargoBase, ref Container> new_showed_cargos = new ref map<CargoBase, ref Container>;
		auto cargoes = VicinityItemManager.GetInstance().GetVicinityCargos();
		for ( i = 0; i < cargoes.Count(); i++ )
		{
			CargoBase cgo = cargoes.Get( i );
			if( cgo)
			{
				if (game_inventory && !m_ShowedCargos.Contains( cgo ) )
				{
					ContainerWithCargo pxc = new ContainerWithCargo( this, -1 );
					pxc.SetEntity( cgo.GetCargoOwner(), cgo.GetOwnerCargoIndex() );
					new_showed_cargos.Insert( cgo, pxc );
					pxc.UpdateInterval();
				}
				else
				{
					if( m_ShowedCargos.Get( cgo ) )
					{
						new_showed_cargos.Insert( cgo, m_ShowedCargos.Get( cgo ) );
					}
				}
			}
		}


//			Print(m_ShowedItems.Count());
		
		for ( i = 0; i < m_ShowedItems.Count(); i++ )
		{
			EntityAI ent = m_ShowedItems.GetKey( i );
			m_ShowedItems.GetElement( i ).UpdateInterval();
			if( !new_showed_items.Contains( ent ) )
			{
				Container con = m_ShowedItems.GetElement( i );
				GetMainWidget().Update();
				Container.Cast( GetParent() ).Remove( con );
				Remove( con );
			}
		}
		
		for ( int ic = 0; ic < m_ShowedCargos.Count(); ic++ )
		{
			CargoBase cgo2 = m_ShowedCargos.GetKey( ic );
			m_ShowedCargos.GetElement( ic ).UpdateInterval();
			if( !new_showed_cargos.Contains( cgo2 ) )
			{
				Container con2 = m_ShowedCargos.GetElement( ic );
				GetMainWidget().Update();
				Container.Cast( GetParent() ).Remove( con2 );
				Remove( con2 );
			}
		}
		
		m_ShowedItems = new_showed_items;
		m_ShowedItemsIDs = showed_items_IDs;
		m_ShowedCargos = new_showed_cargos;
		RecomputeOpenedContainers();
		UpdateCollapseButtons();
		m_VicinityIconsContainer.ShowItemsInContainers( m_ShowedItemIcons );
		
		if( m_ShowedItemIcons.Count() < m_OldShowedItemIconsCount )
		{
			Inventory in = Inventory.Cast( GetRoot() );
			if( in )
				in.UpdateConsoleToolbar();	
		}
	}

};