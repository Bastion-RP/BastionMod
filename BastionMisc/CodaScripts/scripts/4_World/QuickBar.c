//Extends QuickBar to MAX at all times regardless of clothing types
modded class QuickBarBase
{	
	override void SetSize(int newSize)
	{
		super.SetSize(MAX_QUICKBAR_SLOTS_COUNT);
	}
	override int GetSize()
	{
		return MAX_QUICKBAR_SLOTS_COUNT;
	}
}