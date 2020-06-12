modded class ActionOpenBarrelHoles: ActionInteractBase
{
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		Object target_object = target.GetObject();
		BRP_FurnaceFireplace brpfurnace = BRP_FurnaceFireplace.Cast( target.GetObject() );
		if ( target_object.IsItemBase() )
		{
			BarrelHoles_ColorBase ntarget = BarrelHoles_ColorBase.Cast( target_object );
			if( ntarget && !brpfurnace )
			{
				if ( !ntarget.IsOpen() && !ntarget.IsItemTypeAttached( ntarget.ATTACHMENT_COOKING_POT ) )
				{
					return true;
				}
			}
			else
			{
				if ( !ntarget.IsOpen() )
				{
					return true;
				}
			}
		}
		return false;
	}
}
