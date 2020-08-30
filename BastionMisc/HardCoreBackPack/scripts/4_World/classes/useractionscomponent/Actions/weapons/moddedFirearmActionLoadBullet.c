modded class FirearmActionLoadBullet : FirearmActionBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		bool ret = super.ActionCondition(player, target, item);
		
		if(ret)
		{
			Magazine mag = Magazine.Cast(target.GetObject());
			
			InventoryLocation il = new InventoryLocation;
			mag.GetInventory().GetCurrentInventoryLocation( il);
			EntityAI parrent = il.GetParent();
			
			if(player.GetBackPackId() == parrent.GetID() && player.GetBackPackClass() == parrent.ClassName())
				ret = false;
		}

		return ret;
	}
}
modded class ActionLoadMagazineQuick: ActionContinuousBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		return super.ActionCondition(player, target, item);;
	}
}
modded class FirearmActionLoadBulletQuick : FirearmActionBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		return super.ActionCondition(player, target, item);;
	}
}

modded class FirearmActionLoadMultiBullet : FirearmActionBase
{

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		return super.ActionCondition(player, target, item);;
	}
}

modded class FirearmActionLoadMultiBulletQuick : FirearmActionBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item ) //condition for action
	{
		player.GetWeaponManager().SetPlayer(player);
		return super.ActionCondition(player, target, item);;
	}
}