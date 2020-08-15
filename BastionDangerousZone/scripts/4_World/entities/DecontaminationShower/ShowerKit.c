class BRP_ShowerKit extends BRP_Kit
{
  void BRP_ShowerKit()
  {

  }

  override string Get_ItemName()
	{
		return "BRP_DecontaminationShower";
	}

    /*override void OnPlacementComplete( Man player )
    {
        super.OnPlacementComplete( player );

        PlayerBase pb = PlayerBase.Cast( player );
        if ( GetGame().IsServer() )
        {
            PlayerBase player_base = PlayerBase.Cast( player );
            vector position = player_base.GetLocalProjectionPosition();
            vector orientation = player_base.GetLocalProjectionOrientation();

            BRP_DecontaminationShower Shower = BRP_DecontaminationShower.Cast(GetGame().CreateObject("BRP_DecontaminationShower", pb.GetLocalProjectionPosition(), false ));
            Shower.SetPosition( position);
            Shower.SetOrientation( orientation );

            this.Delete();
        }

        SetIsDeploySound( true );
    }*/

  /*override void SetActions()
	{
		super.SetActions();
		AddAction(ActionTogglePlaceObject);
		AddAction(ActionDeployObject);
	}*/
}
