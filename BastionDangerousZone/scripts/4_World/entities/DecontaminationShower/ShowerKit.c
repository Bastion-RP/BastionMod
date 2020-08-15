class ShowerKit extends ItemBase
{
  void ShowerKit()
  {

  }

  //! returns item behaviour of item (more in ItemBase)
	/*override bool IsHeavyBehaviour()
	{
		return true;
	}*/

	//! returns item behaviour of item (more in ItemBase)
	/*override bool IsOneHandedBehaviour()
	{
		return false;
	}*/

	//! returns item behaviour of item (more in ItemBase)
	override bool IsTwoHandedBehaviour()
	{
		return true;
	}

  //================================================================
    // ADVANCED PLACEMENT
    //================================================================

    override void OnPlacementComplete( Man player )
    {
        super.OnPlacementComplete( player );

        PlayerBase pb = PlayerBase.Cast( player );
        if ( GetGame().IsServer() )
        {
            PlayerBase player_base = PlayerBase.Cast( player );
            vector position = player_base.GetLocalProjectionPosition();
            vector orientation = player_base.GetLocalProjectionOrientation();

            DecontaminationShower Shower = DecontaminationShower.Cast(GetGame().CreateObject("DecontaminationShower", pb.GetLocalProjectionPosition(), false ));
            Shower.SetPosition( position);
            Shower.SetOrientation( orientation );

            this.Delete();
        }

        SetIsDeploySound( true );
    }

  override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}
}
