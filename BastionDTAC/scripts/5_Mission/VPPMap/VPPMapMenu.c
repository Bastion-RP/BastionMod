modded class VPPMapMenu {
    void SetMenuOpen(bool isMenuOpen) {
        super.SetMenuOpen (isMenuOpen);

        if (m_IsMenuOpen) {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLaterByName(this, "RefreshAllMapMarkers", 500, true);
        }
    }

    void RefreshAllMapMarkers() {
        if (!m_IsMenuOpen) {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).RemoveByName(this, "RefreshAllMapMarkers");
            return;
        }
        DisplayClientMarkers();
        DisplayServerMarkers();
        DisplayGroupMarkers();
    }

    void DisplayGroupMarkers() {
        ref BST_DTACGroup group = GetDTACClientGroupManager().GetActiveGroup();

        if (group) {
            ref array<ref BST_DTACGroupMember> arrayMembers = group.GetMembers();

            foreach (BST_DTACGroupMember member : arrayMembers) {
                if (!member || member.GetPlayerData().GetId() == GetGame().GetPlayer().GetIdentity().GetId()) { continue; }

                PlayerBase player = member.GetPlayer();
                vector playerPos;

                if (player && player.IsAlive()) {
                    playerPos = player.GetPosition();
                } else {
                    playerPos = member.GetPlayerData().GetPosition();
                }
                m_MapWidget.AddUserMark(playerPos, GetFormattedName(member.GetPlayerData().GetName()), ARGB(255, 255, 255, 255), "BastionMod\\BastionDTAC\\gui\\img\\circle.paa");
            }
        }
    }

    string GetFormattedName(string name) {
        array<string> nameSplit = new array<string>();
        
        name.Split(" ", nameSplit);

        return "" + nameSplit[0].Substring(0, 1) + ". " + nameSplit[1];
    }
}