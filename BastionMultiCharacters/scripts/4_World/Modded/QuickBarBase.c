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

    override void _SetEntity( EntityAI entity, int index, bool force = false) {
        Print("SETTING ENTITY ON QUICKBAR!!! " + entity + " | " + index);
        super._SetEntity(entity, index, force);
    }

    override void OnSetEntityRequest(ParamsReadContext ctx)
	{
		EntityAI eai = null;
		if (!ctx.Read(eai)) {
            Print("FAILED TO READ " + eai);
            return;
        }
		
		int index = -1;
		if (!ctx.Read(index)) {
            Print("FAILED TO READ " + index);
            return;
        }
		
		bool force = false;
		if (!ctx.Read(force)) {
            Print("FAILED TO READ " + force);
            return;
        }
        Print("SETTING ENTITY SHORTCUT!");
		
		_SetEntityShortcut(eai, index, force);
    }
}