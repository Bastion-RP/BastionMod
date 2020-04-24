modded class UniversalLight extends Switchable_Base
{
	override bool CanPutAsAttachment( EntityAI parent )
	{
		if ( parent.IsKindOf("BastionRPGuns_CSR556") )
		{
			return true;
		}
		return super.CanPutAsAttachment(parent);
	}
}