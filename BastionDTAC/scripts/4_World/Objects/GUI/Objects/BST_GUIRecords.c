class BST_GUIRecords {
    private ref GridSpacerWidget _parent;
    private ref BST_RecordGridSpacer _activeGrid;
    private ref array<ref BST_RecordGridSpacer> _arrGrids;
    
    void BST_GUIRecords(GridSpacerWidget parent) {
        _parent = parent;
        _arrGrids = new array<ref BST_RecordGridSpacer>();

        CheckCurrentGridSpacer();
    }

    void ~BST_GUIRecords() {
        foreach (BST_RecordGridSpacer object : _arrGrids) {
            if (object) {
                delete object;
            }
        }
        if (_activeGrid) {
            delete _activeGrid;
        }
    }
    
    void CheckCurrentGridSpacer() {
        if (!_activeGrid || _activeGrid.GetChildCount() >= 100) {
            _activeGrid = new BST_RecordGridSpacer(_parent);

            _arrGrids.Insert(_activeGrid);
        }
    }

    BST_GUIRecord AddRecord(BST_DTAC_CURL_GeneralRecord record, bool transparent) {
        CheckCurrentGridSpacer();

        BST_GUIRecord newRecord = new BST_GUIRecord(_activeGrid.GetGrid(), record, transparent);

        _activeGrid.AddChild(newRecord);
        return newRecord;
    }

    BST_RecordGridSpacer GetActiveGrid() { return _activeGrid; }
}