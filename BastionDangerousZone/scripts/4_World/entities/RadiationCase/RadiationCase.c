class RadiationCase extends Container_Base
{
	void RadiationCase()
	{

	}

	void ~RadiationCase()
	{

	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		return false;
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		return false;
	}
}
