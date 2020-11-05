modded class QuickBarBase {
    map<EntityAI, int> GetQuickBarEntsInMap() {
        map<EntityAI, int> mapEnts = new map<EntityAI, int>();

        for (int i = 0; i < MAX_QUICKBAR_SLOTS_COUNT; i++) {
            mapEnts.Insert(m_aQuickbarEnts[i].m_entity, i);
        }
        return mapEnts;
    }

    array<ref QuickBarItem> GetQuickBarEntsInArray() {
        array<ref QuickBarItem> arrQuickBarItems = new array<ref QuickBarItem>();

        for (int i = 0; i < MAX_QUICKBAR_SLOTS_COUNT; i++) {
            arrQuickBarItems.Insert(m_aQuickbarEnts[i]);
        }
        return arrQuickBarItems;
    }
}