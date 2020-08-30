modded class FirearmActionAttachMagazine : FirearmActionBase
{	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		bool ret = super.ActionCondition(player, target, item);
		
		return ret;
	}
}

modded class FirearmActionAttachMagazineQuick : FirearmActionBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		bool ret = super.ActionCondition(player, target, item);
		return ret;
	}
}