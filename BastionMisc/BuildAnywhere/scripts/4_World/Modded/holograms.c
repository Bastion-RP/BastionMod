modded class Hologram
{
	override void EvaluateCollision(ItemBase action_item = null)
	{	
		if(IsCollidingGPlot())
			SetIsColliding(true);
		else
			SetIsColliding(false);
	}
};