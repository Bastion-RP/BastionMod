enum CodaGestures:GestureCategories
{
    CODA
};

modded class GesturesMenu
{
	override void GetGestureItems( out ref array<ref GestureMenuItem> gesture_items, GestureCategories category )
	{
		super.GetGestureItems( gesture_items, category );

		if ( category == GestureCategories.CATEGORIES )
		{
			gesture_items.Insert( new GestureMenuItem( CodaGestures.CODA, 					"Injuries", 		GestureCategories.CATEGORIES ) );
			gesture_items.Insert( new GestureMenuItem( GestureCategories.CATEGORY_5, 		"Symptoms", 		GestureCategories.CATEGORIES ) );
		}

		else if ( category == CodaGestures.CODA )
		{
			gesture_items.Insert( new GestureMenuItem( eInjuryHandlerLevels.PRISTINE, 		"Default State", 		CodaGestures.CODA  ) );
			gesture_items.Insert( new GestureMenuItem( eInjuryHandlerLevels.WORN, 			"Minor Injuries", 		CodaGestures.CODA  ) );
			gesture_items.Insert( new GestureMenuItem( eInjuryHandlerLevels.DAMAGED, 		"Moderate Injuries", 	CodaGestures.CODA  ) );
			gesture_items.Insert( new GestureMenuItem( eInjuryHandlerLevels.BADLY_DAMAGED, 	"Severe Injuries", 		CodaGestures.CODA  ) );
			gesture_items.Insert( new GestureMenuItem( eInjuryHandlerLevels.RUINED, 		"Near Death", 			CodaGestures.CODA  ) );
		}

		else if ( category == GestureCategories.CATEGORY_5 )
		{
			gesture_items.Insert( new GestureMenuItem( SymptomIDs.SYMPTOM_COUGH, 			"Cough", 		    GestureCategories.CATEGORY_5  ) );
			gesture_items.Insert( new GestureMenuItem( SymptomIDs.SYMPTOM_SNEEZE, 			"Sneeze", 		    GestureCategories.CATEGORY_5  ) );
			gesture_items.Insert( new GestureMenuItem( SymptomIDs.SYMPTOM_FREEZE, 			"Shiver", 		    GestureCategories.CATEGORY_5  ) );
			gesture_items.Insert( new GestureMenuItem( SymptomIDs.SYMPTOM_HOT, 				"Wipe Sweat", 		GestureCategories.CATEGORY_5  ) );
			gesture_items.Insert( new GestureMenuItem( SymptomIDs.SYMPTOM_UNCONSCIOUS, 		"Faint", 			GestureCategories.CATEGORY_5  ) );
		}
	}

	
	override void ExecuteSelectedItem()
	{
		if ( instance.m_IsCategorySelected && instance.m_SelectedItem )
		{
			if ( !GetGame().IsMultiplayer() || GetGame().IsClient() )
			{				
                PlayerBase player = PlayerBase.Cast( GetGame().GetPlayer() );
                GestureMenuItem gesture;

				instance.m_SelectedItem.GetUserData( gesture );

				if ( gesture )
				{
					if( gesture.GetCategory() == CodaGestures.CODA )
					{
						GetRPCManager().SendRPC( "CodaFramework", "UpdatePlayerHealthState", new Param2< int, eInjuryHandlerLevels >( player.GetIdentity().GetPlayerId(), gesture.GetID() ), false );
					} 
                    else if( gesture.GetCategory() == GestureCategories.CATEGORY_5 ) 
                    {
						GetRPCManager().SendRPC( "CodaFramework", "Symptom", new Param2< int, SymptomIDs >( player.GetIdentity().GetPlayerId(), gesture.GetID() ), false );
					} 
                    else if( player.GetEmoteManager() ) 
                    {	
						player.GetEmoteManager().CreateEmoteCBFromMenu( gesture.GetID() );		
					}
				}
			}
		}
	}

    override void OnMenuRelease()
	{
		if ( RadialMenu.GetInstance().IsUsingMouse() )
		{
			ExecuteSelectedItem();
		}
	}
};
