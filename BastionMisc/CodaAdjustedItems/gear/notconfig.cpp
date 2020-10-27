//Patches for item names and descriptions and a few item weight/size/repair option changes. 
class CfgPatches
{
	class coda_gear
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Gear_Optics",
			"DZ_Weapons_Melee",
			"DZ_Gear_Tools",
			"DZ_Gear_Crafting",
			"DZ_Weapons_Firearms"
		};
	};
};

class cfgVehicles
{
	class Edible_Base;
	class Inventory_Base;
	class Clothing;
	class Apple;
	class PainkillerTablets: Edible_Base
	{
		displayName="Paracetemol";
		descriptionShort="Also known as aceteminophen. Used to treat minor aches and pains, and reduces fever.";
	};
	class Banana: Edible_Base
	{
		displayName="Banana";
		descriptionShort="A yellow-ish banana.";
	};
	class Kiwi: Edible_Base
	{
		displayName="Kiwi";
		descriptionShort="A fuzzy kiwi.";
	};
	class Orange: Edible_Base
	{
		displayName="Orange";
		descriptionShort="An orange orange. Orange you glad it's an orange?";
	};
	class Pear: Edible_Base
	{
		//itemSize[]={1,1};
	};
	class Hammer: Inventory_Base
	{
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
	}
	class Mace: Inventory_Base
	{
		displayName="Flanged Mace";
		descriptionShort="A blunt weapon, a type of club or virge that uses a heavy head on the end of a handle to deliver powerful blows. Consists of a strong, heavy metal shaft, featuring a head made of steel. The head of a military mace is shaped with flanges or knobs to allow greater penetration of plate armour. This mace has most probably ceremonial purpose.";
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
	};
	class FireExtinguisher: Inventory_Base
	{
		displayName="Fire Extinguisher";
		descriptionShort="Doesn't look like it works anymore. The instructions read: 1. Hold upright. Pull ring pin. 2. Start back 10 feet. Aim at base of fire. 3. Squeeze lever. 4. Sweep side to side. Dry chemical powder type.";
	};
	class Shovel: Inventory_Base
	{
		weight=2750;//Half Weight
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeBat";//Changes shovel to be in line with the baseball bat and no longer capable of 1-Hit KO
				range=1.8;
			};
			class Heavy
			{
				ammo="MeleeBat_Heavy";//Changes shovel to be in line with the baseball bat and no longer capable of 1-Hit KO
				range=1.8;
			};
			class Sprint
			{
				ammo="MeleeBat_Heavy";//Changes shovel to be in line with the baseball bat and no longer capable of 1-Hit KO
				range=3.7;
			};
		};
	};
	class Pipe: Inventory_Base
	{
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeBat";//Increases damage to be in line with the baseball bat
				range=1.7;
			};
			class Heavy
			{
				ammo="MeleeBat_Heavy";//Increases damage to be in line with the baseball bat
				range=1.7;
			};
			class Sprint
			{
				ammo="MeleeBat_Heavy";//Increases damage to be in line with the baseball bat
				range=4.0999999;
			};
		};
	};
	class PipeWrench: Inventory_Base
	{
		displayName="Pipe Wrench";
		descriptionShort="An adjustable wrench used for turning soft iron pipes and fittings with a rounded surface. The design of the adjustable jaw allows it to rock in the frame, such that any forward pressure on the handle tends to pull the jaws tighter together.";
	};
	class ItemBook;
	class BookBible: ItemBook
	{
		displayName="The Bible";
		descriptionShort="The Bible";
	};
	class Pitchfork: Inventory_Base
	{
		displayName="Pitchfork";
		descriptionShort="An agricultural tool with a long handle and long, thick, widely seperated pointed tines (also called prongs) used to lift and pitch (throw) loose material, such as hay, straw or leaves. Also capable of stabbing through soft enough objects.";
	};
	class Spraycan_ColorBase;
	class Spraycan_Green: Spraycan_ColorBase
	{
		displayName="Green Spraypaint";
		descriptionShort="A green semi-gloss aerosol spraypaint. Contents under pressure!";
	};
	class Spraycan_Black: Spraycan_ColorBase
	{
		displayName="Black Spraypaint";
		descriptionShort="A black semi-gloss aerosol spraypaint. Contents under pressure!";
	};
	class BaseballBat: Inventory_Base
	{
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
	};
	class CombinationLock: Inventory_Base
	{
		//itemSize[]={2,2};
	};
	class Pliers: Inventory_Base
	{
		//itemSize[]={1,2};
	};
	class BoonieHat_ColorBase: Clothing
	{
		//itemSize[]={2,2};
	};
	class HunterPants_ColorBase: Clothing
	{
		//itemSize[]={3,2};
	};
	class TelescopicBaton: Inventory_Base
	{
		//itemSize[]={1,4};
		descriptionShort="Expandable baton, composed of a cylindrical outer shaft containing telescoping inner shafts that lock into each other when expanded. Portable and dangerous. Open with a flick of the wrist.";
	};
	class FieldShovel: Inventory_Base
	{
		//weight=2750;//Half original weight
		displayName="Field Shovel";
		descriptionShort="An entrenching tool is a collapsible spade used by military forces for a variety of military purposes. Survivalists, freedivers, campers, hikers and other outdoors groups have found it to be indispensable in field use.";
	};
	class MeatTenderizer: Inventory_Base
	{
		displayName="Meat Tenderizer";
		descriptionShort="A hand-powered tool to beat your meat.";//Easter egg lol
	};
	class FishingRod_Base_New;
	class ImprovisedFishingRod: FishingRod_Base_New
	{
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
	};
	class FishingRod: FishingRod_Base_New
	{
		//repairableWithKits[]={5};//Duct Tape
		//repairCosts[]={25};
	};
};
