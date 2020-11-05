class CfgPatches
{
	class BastionChess
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};

class CfgMods
{
    class BastionChess
    {
        dir = "Chess";
        picture = "";
        action = "";
        hideName = 1;
        hidePicture = 1;
        name = "Chess";
        credits = "";
        author = "BastionRP Team";
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
                files[] = {"BastionMod/BastionMisc/Chess/scripts/4_World"};
			};
		};
    };
};

class CfgVehicles
{
	class Inventory_Base;
	class BRP_ChessDeck: Inventory_Base
	{
		scope = 2;
		displayName = "Chess Deck";
		descriptionShort = "Chess is a two-player strategy board game played on a checkered board with 64 squares arranged in an 8×8 square grid.";
		model = "BastionMod\BastionMisc_Data\Chess\deck.p3d";
		rotationFlags = 2;
		weight = 500;
		itemBehaviour=2;		
		absorbency = 0.2;
		itemSize[] = {3,3};
		attachments[] = 
		{
			"ChessFigure1","ChessFigure2","ChessFigure3","ChessFigure4","ChessFigure5","ChessFigure6","ChessFigure7","ChessFigure8",
			"ChessFigure9","ChessFigure10","ChessFigure11","ChessFigure12","ChessFigure13","ChessFigure14","ChessFigure15","ChessFigure16",
			"ChessFigure17","ChessFigure18","ChessFigure19","ChessFigure20","ChessFigure21","ChessFigure22","ChessFigure23","ChessFigure24",
			"ChessFigure25","ChessFigure26","ChessFigure27","ChessFigure28","ChessFigure29","ChessFigure30","ChessFigure31","ChessFigure32",
			"ChessFigure33","ChessFigure34","ChessFigure35","ChessFigure36","ChessFigure37","ChessFigure38","ChessFigure39","ChessFigure40",
			"ChessFigure41","ChessFigure42","ChessFigure43","ChessFigure44","ChessFigure45","ChessFigure46","ChessFigure47","ChessFigure48",
			"ChessFigure49","ChessFigure50","ChessFigure51","ChessFigure52","ChessFigure53","ChessFigure54","ChessFigure55","ChessFigure56",
			"ChessFigure57","ChessFigure58","ChessFigure59","ChessFigure60","ChessFigure61","ChessFigure62","ChessFigure63","ChessFigure64"
		};
		repairableWithKits[] = {5};
		repairCosts[] = {30,25};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\center.rvmat","BastionMod\BastionMisc_Data\Chess\data\deck.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\center.rvmat","BastionMod\BastionMisc_Data\Chess\data\deck.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\center_damage.rvmat","BastionMod\BastionMisc_Data\Chess\data\deck_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\center_damage.rvmat","BastionMod\BastionMisc_Data\Chess\data\deck_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\center_destruct.rvmat","BastionMod\BastionMisc_Data\Chess\data\deck_destruct.rvmat"}}
					};
				};
			};
		};
	};
	
	class BRP_ChessPiece_Base: Inventory_Base
	{
		descriptionShort = "A chess piece, or chessman, is any of the six different types of movable objects used on a chessboard to play the game of chess.";
		rotationFlags = 17;
		weight = 5;
		absorbency = 0.0;
		itemSize[] = {1,1};
		repairableWithKits[] = {5};
		repairCosts[] = {30,25};
		inventorySlot[] = 
		{
			"ChessFigure1","ChessFigure2","ChessFigure3","ChessFigure4","ChessFigure5","ChessFigure6","ChessFigure7","ChessFigure8",
			"ChessFigure9","ChessFigure10","ChessFigure11","ChessFigure12","ChessFigure13","ChessFigure14","ChessFigure15","ChessFigure16",
			"ChessFigure17","ChessFigure18","ChessFigure19","ChessFigure20","ChessFigure21","ChessFigure22","ChessFigure23","ChessFigure24",
			"ChessFigure25","ChessFigure26","ChessFigure27","ChessFigure28","ChessFigure29","ChessFigure30","ChessFigure31","ChessFigure32",
			"ChessFigure33","ChessFigure34","ChessFigure35","ChessFigure36","ChessFigure37","ChessFigure38","ChessFigure39","ChessFigure40",
			"ChessFigure41","ChessFigure42","ChessFigure43","ChessFigure44","ChessFigure45","ChessFigure46","ChessFigure47","ChessFigure48",
			"ChessFigure49","ChessFigure50","ChessFigure51","ChessFigure52","ChessFigure53","ChessFigure54","ChessFigure55","ChessFigure56",
			"ChessFigure57","ChessFigure58","ChessFigure59","ChessFigure60","ChessFigure61","ChessFigure62","ChessFigure63","ChessFigure64"
		};			
		hiddenSelections[]=
		{
			"color"
		};	
		class MeleeModes
		{
			class Default
			{
				ammo = "MeleeLightBlunt";
				range = 1.0;
			};
			class Heavy
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 1.0;
			};
			class Sprint
			{
				ammo = "MeleeLightBlunt_Heavy";
				range = 2.8;
			};
		};
	};	
	
	// White ========================================================	
	class BRP_ChessPiece_WBishop: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Bishop";
		model = "BastionMod\BastionMisc_Data\Chess\bishop.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\bishop_co.paa"
		};		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\bishop.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\bishop.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\bishop_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\bishop_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\bishop_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_ChessPiece_WKing: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "King";
		model = "BastionMod\BastionMisc_Data\Chess\King.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\King_co.paa"
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\King.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\King.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\King_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\King_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\King_destruct.rvmat"}}
					};
				};
			};
		};		
	};
	class BRP_ChessPiece_WKnight: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Knight";
		model = "BastionMod\BastionMisc_Data\Chess\Knight.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Knight_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Knight.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Knight.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Knight_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Knight_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Knight_destruct.rvmat"}}
					};
				};
			};
		};			
	};	
	class BRP_ChessPiece_WPawn: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Pawn";
		model = "BastionMod\BastionMisc_Data\Chess\Pawn.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Pawn_co.paa"
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Pawn.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Pawn.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_destruct.rvmat"}}
					};
				};
			};
		};			
	};	
	class BRP_ChessPiece_WQueen: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Queen";
		model = "BastionMod\BastionMisc_Data\Chess\Queen.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Queen_co.paa"
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Queen.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Queen.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Queen_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Queen_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Queen_destruct.rvmat"}}
					};
				};
			};
		};			
	};		
	class BRP_ChessPiece_WRook: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Rook";
		model = "BastionMod\BastionMisc_Data\Chess\Rook.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Rook_co.paa"
		};	
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Rook.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Rook.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Rook_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Rook_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Rook_destruct.rvmat"}}
					};
				};
			};
		};			
	};		
	
	// Black ========================================================
	class BRP_ChessPiece_BBishop: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Bishop";
		model = "BastionMod\BastionMisc_Data\Chess\bishop.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\bishop_co.paa"
		};		
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\bishop_black.rvmat"
		};				
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\bishop_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\bishop_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\bishop_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\bishop_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\bishop_destruct.rvmat"}}
					};
				};
			};
		};
	};
	class BRP_ChessPiece_BKing: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "King";
		model = "BastionMod\BastionMisc_Data\Chess\King.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\King_co.paa"
		};	
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\King_black.rvmat"
		};				
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\King_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\King_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\King_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\King_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\King_destruct.rvmat"}}
					};
				};
			};
		};		
	};
	class BRP_ChessPiece_BKnight: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Knight";
		model = "BastionMod\BastionMisc_Data\Chess\Knight.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Knight_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Knight_black.rvmat"
		};				
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Knight_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Knight_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Knight_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Knight_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Knight_destruct.rvmat"}}
					};
				};
			};
		};		
	};	
	class BRP_ChessPiece_BPawn: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Pawn";
		model = "BastionMod\BastionMisc_Data\Chess\Pawn.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Pawn_co.paa"
		};	
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Pawn_black.rvmat"
		};				
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Pawn_destruct.rvmat"}}
					};
				};
			};
		};			
	};	
	class BRP_ChessPiece_BQueen: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Queen";
		model = "BastionMod\BastionMisc_Data\Chess\Queen.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Queen_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Queen_black.rvmat"
		};		
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Queen_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Queen_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Queen_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Queen_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Queen_destruct.rvmat"}}
					};
				};
			};
		};			
	};		
	class BRP_ChessPiece_BRook: BRP_ChessPiece_Base
	{
		scope = 2;
		displayName = "Rook";
		model = "BastionMod\BastionMisc_Data\Chess\Rook.p3d";	
		hiddenSelectionsTextures[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Rook_co.paa"
		};	
		hiddenSelectionsMaterials[]=
		{
			"BastionMod\BastionMisc_Data\Chess\data\Rook_black.rvmat"
		};			
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 100;
					healthLevels[] = 
					{
						{1.0,{"BastionMod\BastionMisc_Data\Chess\data\Rook_black.rvmat"}},
						{0.7,{"BastionMod\BastionMisc_Data\Chess\data\Rook_black.rvmat"}},
						{0.5,{"BastionMod\BastionMisc_Data\Chess\data\Rook_damage.rvmat"}},
						{0.3,{"BastionMod\BastionMisc_Data\Chess\data\Rook_damage.rvmat"}},
						{0.0,{"BastionMod\BastionMisc_Data\Chess\data\Rook_destruct.rvmat"}}
					};
				};
			};
		};			
	};	
};

class CfgNonAIVehicles
{
	class ProxyAttachment;
	class ProxyChessFigure1: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure1";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure1.p3d";
	};	
	class ProxyChessFigure2: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure2";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure2.p3d";
	};
	class ProxyChessFigure3: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure3";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure3.p3d";
	};
	class ProxyChessFigure4: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure4";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure4.p3d";
	};	
	class ProxyChessFigure5: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure5";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure5.p3d";
	};	
	class ProxyChessFigure6: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure6";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure6.p3d";
	};		
	class ProxyChessFigure7: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure7";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure7.p3d";
	};		
	class ProxyChessFigure8: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure8";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure8.p3d";
	};		
	class ProxyChessFigure9: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure9";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure9.p3d";
	};	
	class ProxyChessFigure10: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure10";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure10.p3d";
	};	
	class ProxyChessFigure11: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure11";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure11.p3d";
	};	
	class ProxyChessFigure12: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure12";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure12.p3d";
	};	
	class ProxyChessFigure13: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure13";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure13.p3d";
	};	
	class ProxyChessFigure14: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure14";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure14.p3d";
	};	
	class ProxyChessFigure15: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure15";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure15.p3d";
	};		
	class ProxyChessFigure16: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure16";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure16.p3d";
	};	
	class ProxyChessFigure17: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure17";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure17.p3d";
	};			
	class ProxyChessFigure18: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure18";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure18.p3d";
	};			
	class ProxyChessFigure19: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure19";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure19.p3d";
	};	
	class ProxyChessFigure20: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure20";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure20.p3d";
	};	
	class ProxyChessFigure21: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure21";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure21.p3d";
	};		
	class ProxyChessFigure22: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure22";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure22.p3d";
	};		
	class ProxyChessFigure23: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure23";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure23.p3d";
	};			
	class ProxyChessFigure24: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure24";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure24.p3d";
	};			
	class ProxyChessFigure25: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure25";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure25.p3d";
	};			
	class ProxyChessFigure26: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure26";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure26.p3d";
	};			
	class ProxyChessFigure27: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure27";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure27.p3d";
	};			
	class ProxyChessFigure28: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure28";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure28.p3d";
	};	
	class ProxyChessFigure29: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure29";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure29.p3d";
	};		
	class ProxyChessFigure30: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure30";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure30.p3d";
	};		
	class ProxyChessFigure31: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure31";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure31.p3d";
	};		
	class ProxyChessFigure32: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure32";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure32.p3d";
	};		
	class ProxyChessFigure33: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure33";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure33.p3d";
	};		
	class ProxyChessFigure34: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure34";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure34.p3d";
	};	
	class ProxyChessFigure35: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure35";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure35.p3d";
	};	
	class ProxyChessFigure36: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure36";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure36.p3d";
	};	
	class ProxyChessFigure37: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure37";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure37.p3d";
	};	
	class ProxyChessFigure38: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure38";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure38.p3d";
	};	
	class ProxyChessFigure39: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure39";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure39.p3d";
	};	
	class ProxyChessFigure40: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure40";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure40.p3d";
	};	
	class ProxyChessFigure41: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure41";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure41.p3d";
	};		
	class ProxyChessFigure42: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure42";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure42.p3d";
	};			
	class ProxyChessFigure43: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure43";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure43.p3d";
	};			
	class ProxyChessFigure44: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure44";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure44.p3d";
	};			
	class ProxyChessFigure45: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure45";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure45.p3d";
	};			
	class ProxyChessFigure46: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure46";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure46.p3d";
	};			
	class ProxyChessFigure47: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure47";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure47.p3d";
	};		
	class ProxyChessFigure48: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure48";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure48.p3d";
	};		
	class ProxyChessFigure49: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure49";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure49.p3d";
	};		
	class ProxyChessFigure50: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure50";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure50.p3d";
	};		
	class ProxyChessFigure51: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure51";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure51.p3d";
	};		
	class ProxyChessFigure52: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure52";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure52.p3d";
	};	
	class ProxyChessFigure53: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure53";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure53.p3d";
	};	
	class ProxyChessFigure54: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure54";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure54.p3d";
	};	
	class ProxyChessFigure55: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure55";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure55.p3d";
	};	
	class ProxyChessFigure56: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure56";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure56.p3d";
	};	
	class ProxyChessFigure57: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure57";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure57.p3d";
	};	
	class ProxyChessFigure58: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure58";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure58.p3d";
	};	
	class ProxyChessFigure59: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure59";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure59.p3d";
	};	
	class ProxyChessFigure60: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure60";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure60.p3d";
	};	
	class ProxyChessFigure61: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure61";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure61.p3d";
	};	
	class ProxyChessFigure62: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure62";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure62.p3d";
	};	
	class ProxyChessFigure63: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure63";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure63.p3d";
	};		
	class ProxyChessFigure64: ProxyAttachment
	{
	    scope=0;
		inventorySlot="ChessFigure64";
		model="BastionMod\BastionMisc_Data\Chess\proxies\ChessFigure64.p3d";
	};		
};

class CfgSlots
{
	class Slot_ChessFigure1
	{
        name="ChessFigure1";
	    displayName="ChessFigure1";
	    ghostIcon="missing";
	};
	class Slot_ChessFigure2: Slot_ChessFigure1
	{
        name="ChessFigure2";
	    displayName="ChessFigure2";
	};	
	class Slot_ChessFigure3: Slot_ChessFigure1
	{
        name="ChessFigure3";
	    displayName="ChessFigure3";
	};		
	class Slot_ChessFigure4: Slot_ChessFigure1
	{
        name="ChessFigure4";
	    displayName="ChessFigure4";
	};	
	class Slot_ChessFigure5: Slot_ChessFigure1
	{
        name="ChessFigure5";
	    displayName="ChessFigure5";
	};		
	class Slot_ChessFigure6: Slot_ChessFigure1
	{
        name="ChessFigure6";
	    displayName="ChessFigure6";
	};		
	class Slot_ChessFigure7: Slot_ChessFigure1
	{
        name="ChessFigure7";
	    displayName="ChessFigure7";
	};	
	class Slot_ChessFigure8: Slot_ChessFigure1
	{
        name="ChessFigure8";
	    displayName="ChessFigure8";
	};	
	class Slot_ChessFigure9: Slot_ChessFigure1
	{
        name="ChessFigure9";
	    displayName="ChessFigure9";
	};		
	class Slot_ChessFigure10: Slot_ChessFigure1
	{
        name="ChessFigure10";
	    displayName="ChessFigure10";
	};		
	class Slot_ChessFigure11: Slot_ChessFigure1
	{
        name="ChessFigure11";
	    displayName="ChessFigure11";
	};		
	class Slot_ChessFigure12: Slot_ChessFigure1
	{
        name="ChessFigure12";
	    displayName="ChessFigure12";
	};		
	class Slot_ChessFigure13: Slot_ChessFigure1
	{
        name="ChessFigure13";
	    displayName="ChessFigure13";
	};		
	class Slot_ChessFigure14: Slot_ChessFigure1
	{
        name="ChessFigure14";
	    displayName="ChessFigure14";
	};		
	class Slot_ChessFigure15: Slot_ChessFigure1
	{
        name="ChessFigure15";
	    displayName="ChessFigure15";
	};		
	class Slot_ChessFigure16: Slot_ChessFigure1
	{
        name="ChessFigure16";
	    displayName="ChessFigure16";
	};		
	class Slot_ChessFigure17: Slot_ChessFigure1
	{
        name="ChessFigure17";
	    displayName="ChessFigure17";
	};		
	class Slot_ChessFigure18: Slot_ChessFigure1
	{
        name="ChessFigure18";
	    displayName="ChessFigure18";
	};	
	class Slot_ChessFigure19: Slot_ChessFigure1
	{
        name="ChessFigure19";
	    displayName="ChessFigure19";
	};	
	class Slot_ChessFigure20: Slot_ChessFigure1
	{
        name="ChessFigure20";
	    displayName="ChessFigure20";
	};	
	class Slot_ChessFigure21: Slot_ChessFigure1
	{
        name="ChessFigure21";
	    displayName="ChessFigure21";
	};	
	class Slot_ChessFigure22: Slot_ChessFigure1
	{
        name="ChessFigure22";
	    displayName="ChessFigure22";
	};	
	class Slot_ChessFigure23: Slot_ChessFigure1
	{
        name="ChessFigure23";
	    displayName="ChessFigure23";
	};	
	class Slot_ChessFigure24: Slot_ChessFigure1
	{
        name="ChessFigure24";
	    displayName="ChessFigure24";
	};
	class Slot_ChessFigure25: Slot_ChessFigure1
	{
        name="ChessFigure25";
	    displayName="ChessFigure25";
	};	
	class Slot_ChessFigure26: Slot_ChessFigure1
	{
        name="ChessFigure26";
	    displayName="ChessFigure26";
	};	
	class Slot_ChessFigure27: Slot_ChessFigure1
	{
        name="ChessFigure27";
	    displayName="ChessFigure27";
	};	
	class Slot_ChessFigure28: Slot_ChessFigure1
	{
        name="ChessFigure28";
	    displayName="ChessFigure28";
	};	
	class Slot_ChessFigure29: Slot_ChessFigure1
	{
        name="ChessFigure29";
	    displayName="ChessFigure29";
	};	
	class Slot_ChessFigure30: Slot_ChessFigure1
	{
        name="ChessFigure30";
	    displayName="ChessFigure30";
	};	
	class Slot_ChessFigure31: Slot_ChessFigure1
	{
        name="ChessFigure31";
	    displayName="ChessFigure31";
	};
	class Slot_ChessFigure32: Slot_ChessFigure1
	{
        name="ChessFigure32";
	    displayName="ChessFigure32";
	};
	class Slot_ChessFigure33: Slot_ChessFigure1
	{
        name="ChessFigure33";
	    displayName="ChessFigure33";
	};
	class Slot_ChessFigure34: Slot_ChessFigure1
	{
        name="ChessFigure34";
	    displayName="ChessFigure34";
	};
	class Slot_ChessFigure35: Slot_ChessFigure1
	{
        name="ChessFigure35";
	    displayName="ChessFigure35";
	};
	class Slot_ChessFigure36: Slot_ChessFigure1
	{
        name="ChessFigure36";
	    displayName="ChessFigure36";
	};
	class Slot_ChessFigure37: Slot_ChessFigure1
	{
        name="ChessFigure37";
	    displayName="ChessFigure37";
	};
	class Slot_ChessFigure38: Slot_ChessFigure1
	{
        name="ChessFigure38";
	    displayName="ChessFigure38";
	};	
	class Slot_ChessFigure39: Slot_ChessFigure1
	{
        name="ChessFigure39";
	    displayName="ChessFigure39";
	};	
	class Slot_ChessFigure40: Slot_ChessFigure1
	{
        name="ChessFigure40";
	    displayName="ChessFigure40";
	};	
	class Slot_ChessFigure41: Slot_ChessFigure1
	{
        name="ChessFigure41";
	    displayName="ChessFigure41";
	};		
	class Slot_ChessFigure42: Slot_ChessFigure1
	{
        name="ChessFigure42";
	    displayName="ChessFigure42";
	};		
	class Slot_ChessFigure43: Slot_ChessFigure1
	{
        name="ChessFigure43";
	    displayName="ChessFigure43";
	};		
	class Slot_ChessFigure44: Slot_ChessFigure1
	{
        name="ChessFigure44";
	    displayName="ChessFigure44";
	};		
	class Slot_ChessFigure45: Slot_ChessFigure1
	{
        name="ChessFigure45";
	    displayName="ChessFigure45";
	};		
	class Slot_ChessFigure46: Slot_ChessFigure1
	{
        name="ChessFigure46";
	    displayName="ChessFigure46";
	};		
	class Slot_ChessFigure47: Slot_ChessFigure1
	{
        name="ChessFigure47";
	    displayName="ChessFigure47";
	};	
	class Slot_ChessFigure48: Slot_ChessFigure1
	{
        name="ChessFigure48";
	    displayName="ChessFigure48";
	};	
	class Slot_ChessFigure49: Slot_ChessFigure1
	{
        name="ChessFigure49";
	    displayName="ChessFigure49";
	};	
	class Slot_ChessFigure50: Slot_ChessFigure1
	{
        name="ChessFigure50";
	    displayName="ChessFigure50";
	};	
	class Slot_ChessFigure51: Slot_ChessFigure1
	{
        name="ChessFigure51";
	    displayName="ChessFigure51";
	};	
	class Slot_ChessFigure52: Slot_ChessFigure1
	{
        name="ChessFigure52";
	    displayName="ChessFigure52";
	};
	class Slot_ChessFigure53: Slot_ChessFigure1
	{
        name="ChessFigure53";
	    displayName="ChessFigure53";
	};
	class Slot_ChessFigure54: Slot_ChessFigure1
	{
        name="ChessFigure54";
	    displayName="ChessFigure54";
	};
	class Slot_ChessFigure55: Slot_ChessFigure1
	{
        name="ChessFigure55";
	    displayName="ChessFigure55";
	};	
	class Slot_ChessFigure56: Slot_ChessFigure1
	{
        name="ChessFigure56";
	    displayName="ChessFigure56";
	};	
	class Slot_ChessFigure57: Slot_ChessFigure1
	{
        name="ChessFigure57";
	    displayName="ChessFigure57";
	};	
	class Slot_ChessFigure58: Slot_ChessFigure1
	{
        name="ChessFigure58";
	    displayName="ChessFigure58";
	};	
	class Slot_ChessFigure59: Slot_ChessFigure1
	{
        name="ChessFigure59";
	    displayName="ChessFigure59";
	};	
	class Slot_ChessFigure60: Slot_ChessFigure1
	{
        name="ChessFigure60";
	    displayName="ChessFigure60";
	};	
	class Slot_ChessFigure61: Slot_ChessFigure1
	{
        name="ChessFigure61";
	    displayName="ChessFigure61";
	};		
	class Slot_ChessFigure62: Slot_ChessFigure1
	{
        name="ChessFigure62";
	    displayName="ChessFigure62";
	};		
	class Slot_ChessFigure63: Slot_ChessFigure1
	{
        name="ChessFigure63";
	    displayName="ChessFigure63";
	};		
	class Slot_ChessFigure64: Slot_ChessFigure1
	{
        name="ChessFigure64";
	    displayName="ChessFigure64";
	};		
};
