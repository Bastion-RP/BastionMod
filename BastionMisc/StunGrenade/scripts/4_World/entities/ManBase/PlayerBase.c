modded class PlayerBase extends ManBase
{
	ref array<ref SGFaceProtection> ProtectGearList; 
	int SGTimerCheck=0;
	int SGShock=0;
	
	override void Init()
	{
		super.Init();
		ProtectGearList = new ref array<ref SGFaceProtection>;		
	}
	
	void CheckProtectionAgainstStun()
	{
		if (GetGame().IsServer())
		{
			/*for(int i=0;i<this.ProtectGearList.Count();i++)
			{
				//Print("this.ProtectGearList.Count(): " + this.ProtectGearList.Count().ToString());
				EntityAI SuitsPart;
				SuitsPart = this.FindAttachmentBySlotName("Mask");
				
				if (SuitsPart == NULL || SuitsPart.IsRuined())
				{			
					//Print("GiveShock IF");
					GiveShock(-100);
					return;
				}
				else
				{
					if((SuitsPart.IsKindOf(this.ProtectGearList.Get(i).PGName))
					{
						//Print("GiveShock: ELSE"+ProtectGearList.Get(i).PGProtection.ToString());
						SGShock+=ProtectGearList.Get(i).PGProtection;
						if(SGShock>=100)
						{
							GiveShock(-100);
							SGShock=0;
						}
					}
				}
			}*/
			bool isFined = false;
			EntityAI SuitsPart;
			SuitsPart = this.FindAttachmentBySlotName("Mask");
			if (SuitsPart == NULL || SuitsPart.IsRuined())
			{
				GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
				GiveShock( -10 );
				return;
			}
			for( int i=0; i<this.ProtectGearList.Count(); i++ )
			{
				if((SuitsPart.IsKindOf(this.ProtectGearList.Get(i).PGName))
				{
					SGShock += ProtectGearList.Get(i).PGProtection;
					isFined = true;
					break;
				}
			}
			if(SGShock >= 100)
			{
				GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
				GiveShock( -10 );
				SGShock = 0;
				return;
			}
			if(!isFined)
			{
				GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs.SYMPTOM_COUGH);
				GiveShock(-10);
				return;
			}
		}
	}
	
	void AddProtectiveGear(string name, int protection)
	{
		ProtectGearList.Insert(new ref SGFaceProtection(name, protection));
	}
}

class SGFaceProtection
{
	string PGName;
	int PGProtection;
	
	void SGFaceProtection(string pgname, int pgprotection)
	{
		PGName=pgname;
		PGProtection=pgprotection;
	}
}


