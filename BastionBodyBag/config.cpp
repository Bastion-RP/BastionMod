class CfgPatches
{
	class BastionBodyBag
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","BastionBodyBag_Data"};
	};
};
class CfgMods
{
	class BastionBodyBag
	{
		dir = "BastionBodyBag";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BastionBodyBag";
		credits = "Kerkkoh";
		author = "Kerkkoh";
		authorID = "0";
		version = "1.0";
		extra = 0;
		type = "mod";
		dependencies[] = {"Game", "World", "Mission"};
		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionBodyBag/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionBodyBag/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"BastionMod/BastionBodyBag/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{    
    class HouseNoDestruct; 
	class BRP_dead_pile1: HouseNoDestruct
    {
        scope = 1;
        model = "\DZ\structures\specific\deadbodies\dead_pile1.p3d";
    };
    class BRP_dead_pile2: HouseNoDestruct
    {
        scope = 1;
        model = "\DZ\structures\specific\deadbodies\dead_pile2.p3d";
    };
    class BRP_dead_pile3: HouseNoDestruct
    {
        scope = 1;
        model = "\DZ\structures\specific\deadbodies\dead_pile3.p3d";
    };
    class BRP_dead_pile4: HouseNoDestruct
    {
        scope = 1;
        model = "\DZ\structures\specific\deadbodies\dead_pile4.p3d";
    };
};