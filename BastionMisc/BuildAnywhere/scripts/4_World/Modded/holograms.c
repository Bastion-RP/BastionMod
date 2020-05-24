modded class Hologram
{
	override void EvaluateCollision()
	{	
		if(IsCollidingGPlot())
			SetIsColliding(true);
		else
			SetIsColliding(false);
	}
};