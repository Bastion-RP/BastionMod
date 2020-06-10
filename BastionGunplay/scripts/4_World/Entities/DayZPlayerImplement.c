modded class DayZPlayerImplement {
	//
	bool CanJump() {

		PlayerBase playerPB = PlayerBase.Cast(this);

		if (playerPB) {
			if (GetItemAccessor() && playerPB.GetItemInHands()) {
				// no guns allowed
				if (GetItemAccessor().IsItemInHandsWeapon() || playerPB.GetItemInHands().IsMeleeWeapon()) {
					return false;
				};
			};
		};
		return super.CanJump();
	}
}