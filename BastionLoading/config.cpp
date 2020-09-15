class CfgPatches
{
    class BastionLoadingScreen
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]=
        {
            "DZ_Data"
        };
    };
};

class CfgMods
{
    class BastionLoadingScreen
    {
        dir="BastionMod/BastionLoading";
        picture="";
        action="";
        hideName=0;
        hidePicture=0;
        name="";
        credits="";
        author="";
        authorID="";
        version="1";
        extra=0;
        type="mod";
        dependencies[]=
        {
            "Game",
            "World",
            "Mission"
        };
        class defs
        {
            class gameScriptModule
            {
                value="";
                files[]=
                {
                    "BastionMod/BastionLoading/scripts/3_Game"
                };
            };
            class worldScriptModule
            {
                value="";
                files[]=
                {
                    "BastionMod/BastionLoading/scripts/4_World"
                };
            };
            class missionScriptModule
            {
                value="";
                files[]=
                {
                    "BastionMod/BastionLoading/scripts/5_Mission"
                };
            };
        };
    };
};