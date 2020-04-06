class CfgPatches
{
	class BastionVendor
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"JM_CF_Scripts",
			"DZ_Data",
			"DZ_Gear_Navigation"
		};
	};
};

class CfgMods
{
	class BastionVendor
	{
		dir = "BastionVendor";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionVendor";
		credits = "CAMINOonPC";
		author = "CAMINOonPC";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game","World","Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionVendor/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionVendor/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionVendor/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class DayZPlayer;

	class SurvivorM_Mirek;
	class SurvivorM_Denis;
	class SurvivorM_Boris;
	class SurvivorM_Cyril;
	class SurvivorM_Elias;
	class SurvivorM_Francis;
	class SurvivorM_Guo;
	class SurvivorM_Hassan;
	class SurvivorM_Indar;
	class SurvivorM_Jose;
	class SurvivorM_Kaito;
	class SurvivorM_Lewis;
	class SurvivorM_Manua;
	class SurvivorM_Niki;
	class SurvivorM_Oliver;
	class SurvivorM_Peter;
	class SurvivorM_Quinn;
	class SurvivorM_Rolf;
	class SurvivorM_Seth;
	class SurvivorM_Taiki;
	class SurvivorF_Linda;
	class SurvivorF_Maria;
	class SurvivorF_Frida;
	class SurvivorF_Gabi;
	class SurvivorF_Helga;
	class SurvivorF_Irena;
	class SurvivorF_Judy;
	class SurvivorF_Keiko;
	class SurvivorF_Lina;
	class SurvivorF_Naomi;

	class BastionVendor: DayZPlayer
	{
		scope = 2;
	};

	class BastionVendorMirek: SurvivorM_Mirek
	{
		scope = 2;
	};

	class BastionVendorDenis: SurvivorM_Denis
	{
		scope = 2;
	};
	
	class BastionVendorBoris: SurvivorM_Boris
	{
		scope = 2;
	};

	class BastionVendorCyril: SurvivorM_Cyril
	{
		scope = 2;
	};

	class BastionVendorElias: SurvivorM_Elias
	{
		scope = 2;
	};

	class BastionVendorFrancis: SurvivorM_Francis
	{
		scope = 2;
	};

	class BastionVendorGuo: SurvivorM_Guo
	{
		scope = 2;
	};

	class BastionVendorHassan: SurvivorM_Hassan
	{
		scope = 2;
	};

	class BastionVendorIndar: SurvivorM_Indar
	{
		scope = 2;
	};

	class BastionVendorJose: SurvivorM_Jose
	{
		scope = 2;
	};

	class BastionVendorKaito: SurvivorM_Kaito
	{
		scope = 2;
	};

	class BastionVendorLewis: SurvivorM_Lewis
	{
		scope = 2;
	};

	class BastionVendorManua: SurvivorM_Manua
	{
		scope = 2;
	};

	class BastionVendorNiki: SurvivorM_Niki
	{
		scope = 2;
	};

	class BastionVendorOliver: SurvivorM_Oliver
	{
		scope = 2;
	};

	class BastionVendorPeter: SurvivorM_Peter
	{
		scope = 2;
	};

	class BastionVendorQuinn: SurvivorM_Quinn
	{
		scope = 2;
	};

	class BastionVendorRolf: SurvivorM_Rolf
	{
		scope = 2;
	};

	class BastionVendorSeth: SurvivorM_Seth
	{
		scope = 2;
	};

	class BastionVendorTaiki: SurvivorM_Taiki
	{
		scope = 2;
	};
	
	class BastionVendorLinda: SurvivorF_Linda
	{
		scope = 2;
	};
	
	class BastionVendorMaria: SurvivorF_Maria
	{
		scope = 2;
	};

	class BastionVendorFrida: SurvivorF_Frida
	{
		scope = 2;
	};

	class BastionVendorGabi: SurvivorF_Gabi
	{
		scope = 2;
	};

	class BastionVendorHelga: SurvivorF_Helga
	{
		scope = 2;
	};

	class BastionVendorIrena: SurvivorF_Irena
	{
		scope = 2;
	};

	class BastionVendorJudy: SurvivorF_Judy
	{
		scope = 2;
	};

	class BastionVendorKeiko: SurvivorF_Keiko
	{
		scope = 2;
	};

	class BastionVendorLina: SurvivorF_Lina
	{
		scope = 2;
	};

	class BastionVendorNaomi: SurvivorF_Naomi
	{
		scope = 2;
	};

	class BastionVendorNewDenis: SurvivorM_Denis
	{
		scope = 2;
	};
};