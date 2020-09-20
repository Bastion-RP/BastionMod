class BRP_Blunt extends Clothing
{
	TorchLight m_Light;
	vector m_Pos = Vector(-0.04, 0.2, 0.05);

	string lit_tex = "BastionMod\\BastionSmoking_Data\\Blunt\\data\\blunt_lit_co.paa";
	string lit_mat = "BastionMod\\BastionSmoking_Data\\Blunt\\data\\blunt_lit.rvmat";

	string unlit_tex = "BastionMod\\BastionSmoking_Data\\Blunt\\data\\blunt_co.paa";
	string unlit_mat = "BastionMod\\BastionSmoking_Data\\Blunt\\data\\blunt.rvmat";

	void BRP_Blunt()
	{
	}

	void ~BRP_Blunt()
	{
		RemoveBluntLight();
	}

	void LightBlunt()
	{
		if (m_Light) return;

		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_Light = TorchLight.Cast(ScriptedLightBase.CreateLight(TorchLight, m_Pos));
			//m_Light.AttachOnObject(this, m_Pos);

			m_Light.SetBrightnessTo(3);
			m_Light.SetRadiusTo(0.1);

			BRP_Blunt blunt;
			if (player && Class.CastTo(blunt, player.GetItemOnSlot("Mask")))
			{
				player.AddChild(m_Light, player.GetBoneIndexByName("Head"));
			}

			SetObjectTexture(0, lit_tex);
			SetObjectMaterial(0, lit_mat);
		}
	}

	void UnlightBlunt()
	{
		if (!m_Light) return;

		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		if (!GetGame().IsMultiplayer() || GetGame().IsClient())
		{
			m_Light.FadeOut();
			m_Light.DetachFromParent();
			m_Light = NULL;

			SetObjectTexture(0, unlit_tex);
			SetObjectMaterial(0, unlit_mat);
		}
	}

	void RemoveBluntLight()
	{
		if (!m_Light) return;

		m_Light.FadeOut();
		m_Light.DetachFromParent();
		m_Light = NULL;
	}

	override void EEDelete(EntityAI parent)
	{
		super.EEDelete(parent);
		
		RemoveBluntLight();
	}

	override void OnWasAttached(EntityAI parent, int slot_id)
	{
		//super.OnWasAttached(parent, slot_id);
		if (IsIgnited()) LightBlunt();
	}

	override void OnWasDetached(EntityAI parent, int slot_id)
	{
		//super.OnWasDetached(parent, slot_id);
		if (IsIgnited()) RemoveBluntLight();
	}

	override bool IsClothing()
	{
		return false;
	}

	override bool CanPutInCargo(EntityAI parent)
	{
		return super.CanPutInCargo(parent) && !IsIgnited();
	}

	override bool IsIgnited()
	{
		return GetCompEM().IsWorking();
	}

	override bool CanBeIgnitedBy(EntityAI igniter = NULL)
	{
		PlayerBase player = PlayerBase.Cast(GetHierarchyRootPlayer());
		BRP_Blunt blunt;
		return GetCompEM().CanWork() && GetCompEM().HasEnoughStoredEnergy() && Class.CastTo(blunt, player.GetItemOnSlot("Mask"));
	}

	override bool HasFlammableMaterial()
	{
		return true;
	}

	override void OnIgnitedThis(EntityAI fire_source)
	{
		//super.OnIgnitedThis(fire_source);
		GetCompEM().SwitchOn();
	}

	override void OnWorkStart()
	{
		super.OnWorkStart();
		LightBlunt();
	}
	
	override void OnWorkStop()
	{
		super.OnWorkStop();
		UnlightBlunt();
	}

	override void OnSwitchOn()
	{
		super.OnSwitchOn();
		if (!GetCompEM().HasEnoughStoredEnergy()) GetCompEM().SwitchOff();
	}

	override void OnSwitchOff()
	{
		super.OnSwitchOff();
	}
}