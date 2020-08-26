class RadSickMdfr : ModifierBase {
	static const int RADSICK_AGENT_THRESHOLD_ACTIVATE = 100;
	static const int RADSICK_AGENT_THRESHOLD_DEACTIVATE = 0;
	private ref array<string> m_BleedingSources = { "Head", "Spine", "LeftShoulder", "LeftArm", "RightShoulder", "LeftLeg", "RightLeg", "LeftFoot", "RightFoot" };
	float chanceVomit;
	float chanceBleeding;
	float _lastTimeTick;
	string m_DZState;

	override void Init() {
		m_TrackActivatedTime = false;
		m_ID = DZModifiers.MDF_DZRADSICK;
		m_TickIntervalInactive = DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive = DEFAULT_TICK_TIME_ACTIVE;
	}

	override protected bool ActivateCondition(PlayerBase player) {
		if (player.GetSingleAgentCount(DZAgents.RADSICK) > RADSICK_AGENT_THRESHOLD_ACTIVATE) {
			return true;
		} else {
			return false;
		}
	}

	override protected void OnActivate(PlayerBase player) {
		//if( player.m_NotifiersManager ) player.m_NotifiersManager.AttachByType(eNotifiers.NTF_SICK);
		player.IncreaseDiseaseCount();
		chanceVomit = player.RadChanceVomit;
		chanceBleeding = player.RadChanceBleeding;

#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:" + player.GetIdentity().GetName() + "RadSickness Activated");
#endif
	}

	override protected void OnDeactivate(PlayerBase player) {
		player.DecreaseDiseaseCount();

#ifdef DZDEBUG
		GetDZLogger().LogInfo("player:" + player.GetIdentity().GetName() + "RadSickness Deactivated");
#endif
	}

	override protected bool DeactivateCondition(PlayerBase player) {
		if (player.GetSingleAgentCount(DZAgents.RADSICK) < RADSICK_AGENT_THRESHOLD_DEACTIVATE) {
			return true;
		} else {
			return false;
		}
	}

	override protected void OnTick(PlayerBase player, float deltaT) {
		int radSickAgentCount = player.GetSingleAgentCount(DZAgents.RADSICK);
		int radMultiplier = 1;
		_lastTimeTick += deltaT;

		if (radSickAgentCount < 150) { return; }
		if (radSickAgentCount >= 500) {
			radMultiplier = player.RadHighMultiplier * 2;

			if (_lastTimeTick > 60) {
				_lastTimeTick = 0;
				
				player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
			}
		} else if (radSickAgentCount >= 400) {
			radMultiplier = player.RadHighMultiplier;

			if (_lastTimeTick > 60) {
				_lastTimeTick = 0;

				player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs.SYMPTOM_FEVERBLUR);
			}
		} else if (radSickAgentCount >= 200) {
			radMultiplier = player.RadHighMultiplier;

			if (_lastTimeTick > 60) {
				_lastTimeTick = 0;
				
				if (chanceBleeding > Math.RandomFloatInclusive(0, 1)) {
					player.GetBleedingManagerServer().AttemptAddBleedingSourceBySelection(m_BleedingSources.GetRandomElement());
				}
			}
		} else {
			if (_lastTimeTick > 60) {
				_lastTimeTick = 0;

				if (chanceVomit > Math.RandomFloatInclusive(0, 1)) {
					player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_VOMIT);
				}
			}
		}
		SetLowLevelEffetOnPlayer(radMultiplier, player);
	}

	void SetLowLevelEffetOnPlayer(float RadMultiplier, PlayerBase player) {
		float currHealth, currBlood, removeBlood, removeHealth;

		currHealth = player.GetHealth();
		currBlood = player.GetHealth("GlobalHealth", "Blood");
		removeHealth = (player.RadHealthDamage * RadMultiplier) / (60 / DEFAULT_TICK_TIME_ACTIVE);
		removeBlood = (player.RadBloodLossDamage * RadMultiplier) / (60 / DEFAULT_TICK_TIME_ACTIVE);

		player.AddHealth("", "Health", -removeHealth);
		player.AddHealth("GlobalHealth", "Blood", -removeBlood);
	}
};