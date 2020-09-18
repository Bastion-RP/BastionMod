modded class ActionForceFeed extends ActionForceConsume
{
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		PlayerBase target_player = PlayerBase.Cast(target.GetObject());

		return target_player && target_player.IsRestrained() && super.ActionCondition(player, target, item);
	}
}