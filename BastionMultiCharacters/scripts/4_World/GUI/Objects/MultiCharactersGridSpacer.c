class MultiCharactersGridSpacer {
    private ref array<ref Widget> arrayChildren;
    private ref Widget wRoot, wParent;

    void MultiCharactersGridSpacer(Widget wParent) {
        arrayChildren = new array<ref Widget>();
        this.wParent = wParent;
    }

    void ~MultiCharactersGridSpacer() {
        if (wRoot) {
            wRoot.Unlink();
        }
        foreach (Widget w : arrayChildren) {
            if (w) {
                w.Unlink();
                delete w;
            }
        }
    }

    void AddChild(Widget w) {
        wParent.AddChild(w);
        arrayChildren.Insert(w);
    }
}