class BRP_ChessDeck extends ItemBase
{
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionTogglePlaceObject);
		AddAction(ActionPlaceObject);
    }	
};

class BRP_ChessPiece_Base extends ItemBase {};
class BRP_ChessPiece_WBishop extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_WKing extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_WKnight extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_WPawn extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_WQueen extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_WRook extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BBishop extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BKing extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BKnight extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BPawn extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BQueen extends BRP_ChessPiece_Base {};
class BRP_ChessPiece_BRook extends BRP_ChessPiece_Base {};