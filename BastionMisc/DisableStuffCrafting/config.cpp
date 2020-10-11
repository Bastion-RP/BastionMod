  class CfgPatches
{
	class DisableStuffCrafting
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};
class CfgMods
{
	class DisableStuffCrafting
	{
		type="mod";
		author="Inkota";
		dependencies[]=
		{
			"World"
		};
		dir="DisableStuffCrafting";
		class defs
		{
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"BastionMod\BastionMisc\DisableStuffCrafting\scripts\4_World"
				};
			};
		};
	};
};