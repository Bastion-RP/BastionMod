class SirenProp : ItemBase
{
    void SirenProp()
    {
        if (GetGame().IsClient() || !GetGame().IsMultiplayer())
        {
            GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( Delay, 100, false );
        }
        GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( this.Delete, 31000, false );
    }

    void Delay()
    {
        EffectSound sound =	SEffectManager.PlaySound( "BRPHouseSiren_SoundSet", this.GetPosition() );
        sound.SetSoundAutodestroy( true );
    }
}