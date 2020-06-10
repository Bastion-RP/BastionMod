modded class WeaponManager {
	override void Fire(Weapon_Base wpn) {

		DayZPlayerImplement BRP_GunPlay_t_Dpi = m_player;
        if (BRP_GunPlay_t_Dpi) {
            if (BRP_GunPlay_t_Dpi.GetAimingModel()) {
                BRP_GunPlay_t_Dpi.GetAimingModel().BRP_GunPlay_Fire(wpn);
            };
        };
        
        super.Fire(wpn);
    };
};