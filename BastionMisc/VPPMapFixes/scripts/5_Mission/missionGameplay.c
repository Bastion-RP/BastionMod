modded class MissionGameplay {

    //Checks if server config forces player to have a physical map item to open the map, returns true if player has map, returns true if option is not forced, returns false if option is forced and player has not physical map in inventory
    override bool CanOpenMap () {
        
        // find player class
        PlayerBase t_PB = PlayerBase.Cast(GetGame().GetPlayer());
        if (!t_PB) {
            return false;
        };
        int t_PlayerClass = t_PB.GetMultiCharactersPlayerClass();

        // only continue if player is ISF
        if (t_PlayerClass < BastionClasses.ISF_F || t_PlayerClass > BastionClasses.ISF_E) {
            return false;
        };

        if (!g_Game.ForcedPhysicalMap())
            return true;

        if (g_Game.ForcedPhysicalMap()){
            //Check Inventory for map item
            array<EntityAI> itemsArray = new array<EntityAI>;
            PlayerBase pb;

            if (Class.CastTo(pb,GetGame().GetPlayer())){
                pb.GetInventory().EnumerateInventory(InventoryTraversalType.INORDER, itemsArray); //INORDER,PREORDER
                
                for (int i = 0; i < itemsArray.Count(); i++){
                    if (itemsArray[i] != null){
                        if (itemsArray[i].IsInherited(ChernarusMap) || itemsArray[i].IsInherited(ItemMap) || itemsArray[i].IsKindOf("ChernarusMap"))
                            return true;
                    }
                }
            }
        }
        return false;
    };
};