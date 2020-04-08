class CfgPatches
{
	class BastionBodyBag
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = 
		{
			"DZ_Data"
		};
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
	class Inventory_Base;
	class BST_BodyBag_Base: Inventory_Base
	{
		scope=0;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		descriptionShort="Bag used to store and transport human corpses. Filled with a corpse from the looks of it.";
		quantityBar=1;
		carveNavmesh=1;
		bounding="BSphere";
		overrideDrawArea="3.0";
		visibilityModifier=0.94999999;
		canBeDigged=0;
		alignHologramToTerain=1;
		heavyItem=1;
		itemSize[]={3,7};
		weight = 70000;
		itemBehaviour=0;
		physLayer="item_large";
		simulation="inventoryItem";	
        class AnimationSources
		{
			class Flat
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=0;
			};
			class Curled
			{
				source="user";
				animPeriod=0.0099999998;
				initPhase=1;
			};
        };		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage=0;
					};
					class Blood
					{
						damage=0;
					};
					class Shock
					{
						damage=0;
					};
				};
			};
		};
	};
	class BST_BodyBag : BST_BodyBag_Base
    {
        scope=2;
		displayName="Body bag";		
        model="\BastionMod\BastionBodyBag\data\bodybag.p3d";
        hiddenSelections[]=
        {
            "all"
        };
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionBodyBag\data\textures\bodybag_co.paa"
        };
    };
	
    class BST_BodyBag_Blood : BST_BodyBag
    {
        scope=2;
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionBodyBag\data\textures\bodybag_blood_co.paa"
        };
    };

    class BST_WrappedBody : BST_BodyBag_Base
    {
        scope=2;
		displayName="Wrapped body";		
        model="\BastionMod\BastionBodyBag\data\wrappedbody.p3d";
        hiddenSelections[]=
        {
            "all"
        };
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionBodyBag\data\textures\wrappedbody_co.paa"
        };
    };
	
    class BST_BodyBagKit : Inventory_Base
    {
        scope=2;
		displayName="Body bag kit";
		descriptionShort="Used to store and transport human corpses.";
        model="\BastionMod\BastionBodyBag\data\tarp.p3d";
		itemSize[]={3,2};
		weight = 300;
		itemBehaviour=1;
        rotationFlags=17;
		canBeDigged=0;
        hiddenSelections[]=
        {
            "all"
        };
        hiddenSelectionsTextures[]=
        {
            "BastionMod\BastionBodyBag\data\textures\bodybag_co.paa"
        };
        hiddenSelectionsMaterials[]=
        {
            "BastionMod\BastionBodyBag\data\textures\bodybag.rvmat"
        };
        class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 300;
					healthLevels[] = 
                    {
                        {
                            1.0,
                            {"BastionMod\BastionBodyBag\data\textures\bodybag.rvmat"}
                        },
                        {
                            0.7,
                            {"BastionMod\BastionBodyBag\data\textures\bodybag.rvmat"}
                        },
                        {
                            0.5,
                            {"BastionMod\BastionBodyBag\data\textures\bodybag_damage.rvmat"}
                        },
                        {
                            0.3,
                            {"BastionMod\BastionBodyBag\data\textures\bodybag_damage.rvmat"}
                        },
                        {
                            0.0,
                            {"BastionMod\BastionBodyBag\data\textures\bodybag_destruct.rvmat"}
                        }
                    };
				};
			};
		};
    };
};