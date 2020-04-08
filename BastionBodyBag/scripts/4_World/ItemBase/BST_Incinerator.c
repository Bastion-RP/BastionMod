class BST_Incinerator : FireplaceBase {
    void BST_Incinerator()
    {
        SetOvenState( true );
        SetLifetime( 604800 );
    }

    void SetIncinerationFire( FireplaceFireState state )
    {
        SetFireState( state );
    }
};