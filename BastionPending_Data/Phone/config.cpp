﻿////////////////////////////////////////////////////////////////////
//DeRap: P:\BastionMod\BastionPending_Data\Phone\config.bin
//Produced from mikero's Dos Tools Dll version 7.60
//https://mikero.bytex.digital/Downloads
//'now' is Tue Apr 28 21:15:28 2020 : 'file' last modified on Tue Apr 28 21:15:28 2020
////////////////////////////////////////////////////////////////////

#define _ARMA_

class CfgPatches
{
	class BRP_Phone
	{
		units[] = {"BRP_Phone"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgMods
{
	class BRP_Phone
	{
		dir = "BastionMod";
		picture = "";
		action = "";
		hideName = 1;
		hidePicture = 1;
		name = "BRP_Phone";
		credits = "Helkhiana";
		author = "Kerkkoh";
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
				files[] = {"BastionMod/Phone/scripts/4_World"};
			};
		};
	};
};
class CfgVehicles
{
	class Inventory_Base;
	class BRP_Phone: Inventory_Base
	{
		scope = 2;
		displayName = "Dyerphone V2";
		descriptionShort = "Dyerphone V2";
		model = "\BastionMod\BastionPending_Data\Phone\Bastion_Phone.p3d";
		weight = 250;
		itemSize[] = {2,2};
		itemBehaviour = 1;
		rotationFlags = 1;
		physLayer = "item_large";
		inventorySlot[] = {"WalkieTalkie","BRP_Phone"};
		hiddenSelections[] = {"all"};
		hiddenSelectionsTextures[] = {"BastionMod\BastionPending_Data\Phone\data\bastionphone_co.paa"};
	};
};
class CfgSlots
{
	class Slot_BRP_Phone
	{
		name = "BRP_Phone";
		displayName = "BRP_Phone";
		ghostIcon = "walkietalkie";
	};
};
class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyBastion_Phone: ProxyAttachment
	{
		scope = 2;
		inventorySlot[] = {"BRP_Phone"};
		model = "\BastionMod\BastionPending_Data\Phone\Bastion_Phone.p3d";
	};
};
