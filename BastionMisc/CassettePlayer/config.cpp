class CfgPatches
{
	class BastionCassetePlayer
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
    class CassettePlayer
    {
        dir = "CassettePlayer";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "CassettePlayer";
        credits = "";
        author = "BastionRP Team";
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
                files[] = {"BastionMod/BastionMisc/CassettePlayer/scripts/4_World"};
			};
		};
    };
};

class CfgVehicles
{
	class Inventory_Base;
	class BRP_CassettePlayer: Inventory_Base
	{
		scope = 2;
		displayName = "Cassette Player";
		descriptionShort = "Description";
		model = "BastionMod\BastionMisc_Data\CassettePlayer\walkman.p3d";
//		rotationFlags = 17;
		weight = 300;
		absorbency = 0.2;
		itemSize[] = {2,2};
		attachments[]=
		{
			"cassette"
		};	
		hiddenSelections[]=
		{
			"door",
			"player"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor_ca.paa",			
			"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman_co.paa"
		};			
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman.rvmat","BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman.rvmat","BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman_damage.rvmat","BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman_damage.rvmat","BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\CassettePlayer\data\walkman_destruct.rvmat","BastionMod\BastionMisc_Data\CassettePlayer\data\walkmandoor_destruct.rvmat"}
					}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};
	
	class BRP_Cassette: Inventory_Base
	{
		scope = 2;
		displayName = "Red Cassette";
		descriptionShort = "Description";
		model = "BastionMod\BastionMisc_Data\CassettePlayer\cassette.p3d";
//		rotationFlags = 17;
		weight = 300;
		absorbency = 0.2;
		itemSize[] = {1,2};
		inventorySlot[] = 
		{
			"cassette"
		};			
		hiddenSelections[]=
		{
			"color"
		};
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_co.paa"
		};			
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_destruct.rvmat"}
					}};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};	
	class BRP_Cassette_blue: BRP_Cassette
	{
		displayName = "Blue Cassette";
		descriptionShort = "Description";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_blue_co.paa"
		};			
	};		
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class Proxycassette: ProxyAttachment
	{
	    scope=2;
		inventorySlot="cassette";
		model="BastionMod\BastionMisc_Data\CassettePlayer\cassette.p3d";
	};	
};

class CfgSlots
{
	class Slot_cassette
	{
        name="cassette";
	    displayName="cassette";
	    ghostIcon="missing";
	};
};
