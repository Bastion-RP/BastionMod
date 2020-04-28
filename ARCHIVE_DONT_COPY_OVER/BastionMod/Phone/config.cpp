class CfgPatches
{
	class BastionRP_Phone
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
	class BastionRP_Phone
	{
		dir = "BastionMod";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionRP_Phone";
		credits = "Helkhiana";
		author = "Kerkkoh";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"World"};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/Phone/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class BastionRP_Phone: Inventory_Base
	{
		scope = 2;
		displayName = "Phone";
		descriptionShort = "Phone";
		model = "\BastionMod\Phone\data\Bastion_Phone.p3d";
		weight=250;
		itemSize[]={2,2};
		itemBehaviour=1;
		rotationFlags=1;
		physLayer="item_large";
		inventorySlot[] = {"WalkieTalkie", "BRP_Phone"};
		hiddenSelections[]=
		{
			"all"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\Phone\data\bastionphone_co.paa"
		};
	};
};
class CfgSlots
{
	class Slot_BRP_Phone
	{
		name = "BRP_Phone";
		displayName = "BRP_Phone";
		ghostIcon = "walkietalkie";
	};
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBastion_Phone: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"BRP_Phone"};
		model = "\BastionMod\Phone\data\Bastion_Phone.p3d";
	};
};

