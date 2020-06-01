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
		descriptionShort = "A cassette player that can be used to play cassettes and record others as well as listen to the radio.";
		model = "BastionMod\BastionMisc_Data\CassettePlayer\walkman.p3d";
		rotationFlags = 2;
		weight = 300;
		absorbency = 0.2;
		itemSize[] = {2,2};
		attachments[] = {"BatteryD","Cassette"};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30,25};
		class EnergyManager
		{
			hasIcon = 1;
			autoSwitchOff = 1;
			energyUsagePerSecond = 0.01;
			plugType = 1;
			attachmentAction = 1;
			wetnessExposure = 0.1;
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
		descriptionShort = "A cassette that contains music.";
		model = "BastionMod\BastionMisc_Data\CassettePlayer\cassette.p3d";
		rotationFlags = 17;
		weight = 300;
		absorbency = 0.2;
		itemSize[] = {1,2};
		repairableWithKits[] = {5,7};
		repairCosts[] = {30,25};
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
		descriptionShort = "A cassette that contains music.";
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\CassettePlayer\data\cassette_blue_co.paa"
		};			
	};
	class BRP_USA_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Star-Spangled Banner Cassette";
	};
	class BRP_Electronic_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Electronic Music Cassette";
	};
	class BRP_FourSeasons_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Four Seasons Cassette";
	};
	class BRP_Moazart_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Mozart Cassette";
	};
	class BRP_SadMusic_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Sad Music Cassette";
	};
	class BRP_Scotland_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Scotland the Brave Cassette";
	};
	class BRP_StraussII_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Strauss II Cassette";
	};
	class BRP_SummerMusic_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Summer Music Cassette";
	};
	class BRP_GuitarMusic_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Guitar Music Cassette";
	};
	class BRP_ElectronicTwo_Cassette: BRP_Cassette
	{
		scope = 2;
		displayName = "Electronic Music II Cassette";
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

class CfgSoundShaders
{
	class Custom_SoundShader_Base
	{
		range = 30;
	};
	class USA_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\usaanthem.ogg",1}};
		volume = 1;
	};
	class Electronic_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\electronicOne.ogg",1}};
		volume = 1;
	};
	class FourSeasons_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\fourseasons.ogg",1}};
		volume = 1;
	};
	class Mozart_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\mozart.ogg",1}};
		volume = 1;
	};
	class SadMusic_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\sadmusic.ogg",1}};
		volume = 1;
	};
	class Scotland_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\scotlandthebrave.ogg",1}};
		volume = 1;
	};
	class StraussII_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\straussii.ogg",1}};
		volume = 1;
	};
	class SummerMusic_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\summermusic.ogg",1}};
		volume = 1;
	};
	class GuitarMusic_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\guitarmusic.ogg",1}};
		volume = 1;
	};
	class ElectronicTwo_SoundShader: Custom_SoundShader_Base
	{
		samples[] = {{"BastionMod\BastionMisc\CassettePlayer\sounds\electronicTwo.ogg",1}};
		volume = 1;
	};
};
class CfgSoundSets
{
	class Custom_SoundSet_Base
	{
		sound3DProcessingType = "character3DProcessingType";
		volumeCurve = "characterAttenuationCurve";
		spatial = 1;
		doppler = 0;
		loop = 0;
	};
	class USA_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"USA_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class Electronic_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"Electronic_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class FourSeasons_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"Fourseasons_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class Mozart_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"Mozart_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class SadMusic_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"SadMusic_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class Scotland_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"Scotland_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class StraussII_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"StraussII_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class SummerMusic_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"SummerMusic_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class GuitarMusic_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"GuitarMusic_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
	class ElectronicTwo_SoundSet: Custom_SoundSet_Base
	{
		soundShaders[] = {"ElectronicTwo_SoundShader"};
		frequencyRandomizer = 0;
		volumeRandomizer = 0;
		volume = 1;
	};
};