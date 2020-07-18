modded class ActionForceConsumeSingle
{
    override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
    {
        Object target_object = target.GetObject();

		PlayerBase target_player = PlayerBase.Cast(target_object);

        if (target_player && target_player.MouthClosed())
        { return false; }
        return super.ActionCondition(player,target,item);
    }
}