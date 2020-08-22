void FoldOpticsBRP (EntityAI ParentItem)
{
	protected int foldingOpticRaisedId = -1;
	protected int foldingOpticLoweredId = -1;
	TStringArray selectionNames = new TStringArray;

	ParentItem.ConfigGetTextArray("simpleHiddenSelections",selectionNames);

	foldingOpticRaisedId = selectionNames.Find("folding_raised");
	foldingOpticLoweredId = selectionNames.Find("folding_lowered");  
		
	ParentItem.SetSimpleHiddenSelectionState(foldingOpticRaisedId,false);
	ParentItem.SetSimpleHiddenSelectionState(foldingOpticLoweredId,true);
};

void UnfoldOpticsBRP(EntityAI ParentItem)
{
	protected int foldingOpticRaisedId = -1;
	protected int foldingOpticLoweredId = -1;
	TStringArray selectionNames = new TStringArray;

	ParentItem.ConfigGetTextArray("simpleHiddenSelections",selectionNames);

	foldingOpticRaisedId = selectionNames.Find("folding_raised");
	foldingOpticLoweredId = selectionNames.Find("folding_lowered");  

	ParentItem.SetSimpleHiddenSelectionState(foldingOpticRaisedId,true);
	ParentItem.SetSimpleHiddenSelectionState(foldingOpticLoweredId,false);
};