class BST_CraftingLoadedRecipe : BST_CraftingRecipe {
    private string fileName;

    void SetFileName(string fileName) {
        this.fileName = fileName;
    }

    string GetFileName() { return fileName; }
}