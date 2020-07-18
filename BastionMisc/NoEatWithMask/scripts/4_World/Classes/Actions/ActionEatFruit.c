modded class ActionEatFruit
{
	override bool ActionCondition ( PlayerBase player, ActionTarget target, ItemBase item )
    {
        if (player.MouthClosed())
        { return false; }
        return super.ActionCondition(player,target,item);
    }
}