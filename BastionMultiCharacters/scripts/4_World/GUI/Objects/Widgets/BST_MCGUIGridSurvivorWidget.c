class BST_MCGUIGridSurvivorWidget : BST_MCGUIWidget {
    private ref GridSpacerWidget _grid;
    private ref array<ref BST_MCGUIPlyPreviewSmallWidget> _arrPreviews;
    private ref map<Widget, BST_MCGUIPlyPreviewSmallWidget> _mapPreviews;

    void BST_MCGUIGridSurvivorWidget(Widget parent) {
        _arrPreviews = new array<ref BST_MCGUIPlyPreviewSmallWidget>();
        _mapPreviews = new map<Widget, BST_MCGUIPlyPreviewSmallWidget>();
    }

    void Init(ScriptedWidgetEventHandler handler) {
        _root = GetGame().GetWorkspace().CreateWidgets("BastionMod/BastionMultiCharacters/gui/layout/GridSurvivorPreviewWidget.layout", _parent);
        _grid = GridSpacerWidget.Cast(_root.FindAnyWidget("grid"));
        _handler = handler;

        _root.SetHandler(handler);
    }

    void AddChild(BST_MCGUIPlyPreviewSmallWidget newPreview) {
        _arrPreviews.Insert(newPreview);
        _mapPreviews.Insert(newPreview.GetRoot(), newPreview);
    }

    BST_MCGUIPlyPreviewSmallWidget CreateChild(string charType) {
        BST_MCGUIPlyPreviewSmallWidget newPreview = new BST_MCGUIPlyPreviewSmallWidget(_grid);

        newPreview.Init();
        newPreview.CreateNewPlayer(charType);
        _arrPreviews.Insert(newPreview);
        _mapPreviews.Insert(newPreview.GetRoot(), newPreview);
        return newPreview;
    }

    BST_MCGUIPlyPreviewSmallWidget GetWidget(Widget w) { return _mapPreviews.Get(w); }
    bool HasWidget(Widget w) { return _mapPreviews.Contains(w); }
    int ChildCount() { return _arrPreviews.Count(); }

    void ~BST_MCGUIGridSurvivorWidget() {
        if (_arrPreviews) {
            foreach (BST_MCGUIPlyPreviewSmallWidget widget : _arrPreviews) {
                if (!widget) { continue; }
                delete widget;
            }
        }
        if (_grid) {
            _grid.Unlink();
        }
    }
}