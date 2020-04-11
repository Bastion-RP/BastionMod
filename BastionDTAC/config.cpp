class CfgPatches
{
	class BastionDTAC
	{
		requiredAddons[] = {
            "DZ_Data",
			"VanillaPlusPlus",
			"MultiCharacters"
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
		inputs="BastionDTAC\modded_Inputs.xml";
		version="version 1.0";
		extra=0;
		type="mod";
		dependencies[] = {"Game","World","Mission"};

	    class defs
	    {
            class gameScriptModule
            {
                files[] = {"BastionDTAC\scripts\3_Game"};
            };
            class worldScriptModule
            {
                files[] = {"BastionDTAC\scripts\4_World"};
            };
            class missionScriptModule
            {
                files[] = {"BastionDTAC\Scripts\5_Mission"};
            };
        };
    };
};