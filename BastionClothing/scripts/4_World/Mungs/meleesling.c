class BRP_meleesling_colorbase extends Clothing
{

	private void HideUnhideSelection(string selectionName, bool hide = false)
    {
        TStringArray selectionNames = new TStringArray;
        ConfigGetTextArray("simpleHiddenSelections",selectionNames);
        int selectionId = selectionNames.Find(selectionName);
        SetSimpleHiddenSelectionState(selectionId, hide);
    }

    override void EEInit()
	{
		super.EEInit();
		HideUnhideSelection("deployed", 0);
        HideUnhideSelection("rolled", 1);
	}

	override bool CanReceiveAttachment( EntityAI attachment, int slotId )
	{
		if ( attachment.!IsKindOf("RifleCore"))
		{
			return true;
		}
		return false;
	}

	override void EEItemAttached( EntityAI item, string slot_name )
	{
			super.EEItemAttached(item, slot_name);
            HideUnhideSelection("deployed", 1);
            HideUnhideSelection("rolled", 0);
            
            if(item.!IsKindOf("Sword"))
            {
            	HideUnhideSelection("sword", 0);
            	HideUnhideSelection("axe", 1);
            }
            if(item.IsKindOf("Sword"))
            {
            	HideUnhideSelection("sword", 1);
            	HideUnhideSelection("axe", 0);
            }
	}

	override void EEItemDetached( EntityAI item, string slot_name )
	{
			super.EEItemDetached(item, slot_name);
            HideUnhideSelection("deployed", 0);
            HideUnhideSelection("rolled", 1);
	}
};