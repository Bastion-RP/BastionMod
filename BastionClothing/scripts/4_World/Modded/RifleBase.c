modded class Rifle_Base extends Weapon_Base
{
	override bool CanPutAsAttachment( EntityAI parent )
	{	

		if( parent.IsMan() )
		{
			return false;
		}
		return true;
        return super.CanPutAsAttachment(parent);		
	}
};