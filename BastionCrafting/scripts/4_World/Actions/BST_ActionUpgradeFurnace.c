class BST_ActionUpgradeFurnaceCB : ActionContinuousBaseCB {
	PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
	override void CreateActionComponent() {
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.DEFAULT_CONSTRUCT);
	}
};

class BST_ActionUpgradeFurnace : ActionContinuousBase {
	protected Object BRP_FurnaceFireplace_1;

	void BST_ActionUpgradeFurnace() {
		m_CallbackClass = BST_ActionUpgradeFurnaceCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_ASSEMBLE;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.ROUGH_HIGH;
	}

	override void CreateConditionComponents() {
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNonRuined(UAMaxDistances.BASEBUILDING);
	}

	override string GetText() {
		return "Build Furnace";
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
		BRP_Furnace furnace = BRP_Furnace.Cast(target.GetObject());
		
		if (furnace) {
			if (furnace.CanUpgrade()) {
				return true;
			}
		}
		return false;
	}

	override void OnFinishProgressServer(ActionData action_data) {
		//target existing model
		BRP_Furnace furnace = BRP_Furnace.Cast(action_data.m_Target.GetObject());

		if (furnace) {
			//create new model
			vector position = furnace.GetPosition();
			vector orientation = furnace.GetOrientation();
			vector positionOffset = "0.08 0.86 0";
			//vector orientationOffset = "-90 0 0";
			BRP_FurnaceFireplace fireplace = BRP_FurnaceFireplace.Cast(GetGame().CreateObject("BRP_FurnaceFireplace", furnace.GetPosition(), false));

			if (fireplace) {
				BRP_FurnaceFireplace_1.SetPosition(position + positionOffset);
				BRP_FurnaceFireplace_1.SetOrientation(orientation);
			}
			//delete existing model
			furnace.Delete();

			//add damage to tool
			action_data.m_MainItem.DecreaseHealth(UADamageApplied.BUILD, false);
		}
		action_data.m_Player.MessageStatus((furnace.GetPosition() - action_data.m_Player.GetPosition()).ToString());
		action_data.m_Player.GetSoftSkillsManager().AddSpecialty(m_SpecialtyWeight);
	}
}