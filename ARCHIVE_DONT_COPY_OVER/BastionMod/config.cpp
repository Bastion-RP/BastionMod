class CfgPatches
{
	class BastionMod
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
		};
	};
};
class CfgMods
{
	class BastionMod
	{
		dir="";
		picture="";
		action="";
		hideName=1;
		hidePicture=1;
		name="BastionMod";
		credits="Hop";
		author="Hop";
		authorID="0";
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\Guns\scripts\4_world"
				};
			};
		};
	};
};
