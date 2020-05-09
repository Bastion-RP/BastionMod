modded class Weapon_Base {
    bool IsISFWeapon() {
        return false;
    }

    /*     override bool CanPutInCargo(EntityAI parent) {
            if (IsISFWeapon()) {
                PlayerBase player;
                if (Class.CastTo(player, parent)) {
                    if (player.GetMultiCharactersPlayerClass() == 5)
                        return super.CanPutInCargo(parent);
                    return false;
                }
            }
            return super.CanPutInCargo(parent);
        } */

    override bool CanPutIntoHands(EntityAI parent) {
        if (IsISFWeapon()) {
            PlayerBase player;
            if (Class.CastTo(player, parent)) {
                if (player.GetMultiCharactersPlayerClass() == 5)
                    return super.CanPutIntoHands(parent);
                return false;
            }
        }
        return super.CanPutIntoHands(parent);
    }

    /* override bool CanPutAsAttachment(EntityAI parent) {
        if (IsISFWeapon()) {
            PlayerBase player;
            if (Class.CastTo(player, parent)) {
                if (player.GetMultiCharactersPlayerClass() == 5)
                    return super.CanPutAsAttachment(parent);
                return false;
            }
        }
        return super.CanPutAsAttachment(parent);
    } */
}