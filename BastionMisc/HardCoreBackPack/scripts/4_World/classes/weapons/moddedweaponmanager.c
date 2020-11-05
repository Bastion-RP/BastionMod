modded class WeaponManager
{
	private PlayerBase playerBase;
	void SetPlayer(PlayerBase _playerBase)
	{
		playerBase = _playerBase;
	}
	
	override bool CanAttachMagazine(Weapon_Base wpn, Magazine mag, bool reservationCheck = true )
	{
		bool ret = super.CanAttachMagazine(wpn, mag, reservationCheck);
		if(ret)
		{
			
			InventoryLocation il = new InventoryLocation;
			mag.GetInventory().GetCurrentInventoryLocation( il);
			EntityAI parrent = il.GetParent();
			if(parrent != null)
			{			
				ItemBase itemAnalize;
				il = new InventoryLocation;
				parrent.GetInventory().GetCurrentInventoryLocation( il);
				itemAnalize = il.GetParent();
				if(playerBase != null)
				{
					ret = AnalizeItem(parrent);
					if(ret)
					{
						if(itemAnalize != null)
							ret = AnalizeItem(itemAnalize);
					}
				}
			}
			
		}

		return ret;
	}
	bool AnalizeItem(Entity entityAI)
	{
		bool ret = true;
		ref array<int> attachToBackPackIds = playerBase.GetAttackToBackPackIds(); 
		ref array<string> attachToBackPackClassName = playerBase.GetSttachToBackPackClassName(); 
		int backPackId  = playerBase.GetBackPackId(); 
		string backPackClass = playerBase.GetBackPackClass();
		
		if( backPackId == entityAI.GetID() && backPackClass == entityAI.ClassName())
			return false;
		
		for(int i = 0; i <=  attachToBackPackIds.Count(); i++)
		{
			int Idx = attachToBackPackIds[i];
			string className = attachToBackPackClassName[i];
			if( Idx == entityAI.GetID() && className == entityAI.ClassName())
				return false;
		}
		
		return ret;
	}
	override bool CanSwapMagazine(Weapon_Base wpn, Magazine mag, bool reservationCheck = true)
	{
		bool ret = super.CanSwapMagazine(wpn, mag, reservationCheck);
		if(ret)
		{
			
			InventoryLocation il = new InventoryLocation;
			mag.GetInventory().GetCurrentInventoryLocation( il);
			EntityAI parrent = il.GetParent();
			if(parrent != null)
			{			
				ItemBase itemAnalize;
				il = new InventoryLocation;
				parrent.GetInventory().GetCurrentInventoryLocation( il);
				itemAnalize = il.GetParent();
				if(playerBase != null)
				{
					ret = AnalizeItem(parrent);
					if(ret)
					{
						if(itemAnalize != null)
							ret = AnalizeItem(itemAnalize);
					}
				}
			}
		}

		return ret;
	}

	override bool CanLoadBullet(Weapon_Base wpn, Magazine mag, bool reservationCheck = true)
	{
		bool ret = super.CanLoadBullet(wpn, mag, reservationCheck);
		if(ret)
		{
			
			InventoryLocation il = new InventoryLocation;
			mag.GetInventory().GetCurrentInventoryLocation( il);
			EntityAI parrent = il.GetParent();
			if(parrent != null)
			{			
				ItemBase itemAnalize;
				il = new InventoryLocation;
				parrent.GetInventory().GetCurrentInventoryLocation( il);
				itemAnalize = il.GetParent();
				if(playerBase != null)
				{
					ret = AnalizeItem(parrent);
					if(ret)
					{
						if(itemAnalize != null)
							ret = AnalizeItem(itemAnalize);
					}
				}
			}
			
		}

		return ret;
	}
	
	override Magazine GetPreparedMagazine ()
	{
		for(int i = 0; i < m_SuitableMagazines.Count(); i++)
		{
			if(m_SuitableMagazines.Get(i).GetAmmoCount() > 0)
			{
				Magazine mag = Magazine.Cast(m_SuitableMagazines.Get(i));
				InventoryLocation il = new InventoryLocation;
				mag.GetInventory().GetCurrentInventoryLocation( il);
				EntityAI parrent = il.GetParent();
				if(playerBase != null)
				{
					
					if(AnalizeItem(parrent))
					{
						ItemBase itemAnalize;
						il = new InventoryLocation;
						parrent.GetInventory().GetCurrentInventoryLocation( il);
						itemAnalize = il.GetParent();
						if(itemAnalize != null)
						{
							if(AnalizeItem(itemAnalize))
							{
								return m_SuitableMagazines.Get(i);
							}
						}
						else
						{
							return m_SuitableMagazines.Get(i);
						}
					}
				}
			}
		}
		return null;
	}
	
	
	
	
}