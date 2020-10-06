class CfgPatches
{
	class BastionDTAC
	{
		requiredAddons[] = {
            "DZ_Data",
			"VanillaPlusPlus",
			"BastionMultiCharacters",
			"BastionCentralMenu"
        };
	};
};

class CfgMods
{
	class BastionDTAC
	{
		dir="BastionDTAC";
		hideName=0;
		hidePicture=0;
		name="Bastion DTAC";
		credits="RoomService";
		author="RoomService";
		authorID="999999";
		inputs="BastionMod/BastionDTAC/modded_Inputs.xml";
		version="version 1.0";
		extra=0;
		type="mod";
		dependencies[] = {"Game","World","Mission"};

	    class defs
	    {
            class gameScriptModule
            {
                files[] = {"BastionMod/BastionDTAC/scripts/3_Game"};
            };
            class worldScriptModule
            {
                files[] = {"BastionMod/BastionDTAC/scripts/4_World"};
            };
            class missionScriptModule
            {
                files[] = {"BastionMod/BastionDTAC/Scripts/5_Mission"};
            };
        };
    };
};