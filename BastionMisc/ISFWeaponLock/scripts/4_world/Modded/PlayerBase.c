modded class PlayerBase {
    override bool CanReceiveItemIntoHands(EntityAI item_to_hands) {
        Weapon_Base weap = Weapon_Base.Cast(item_to_hands);

        if (weap && weap.IsISFWeapon()) {
            if (GetMultiCharactersPlayerClass() == 5)
                return true;

            return false;
        }
        return super.CanReceiveItemIntoHands(item_to_hands);
    }
}