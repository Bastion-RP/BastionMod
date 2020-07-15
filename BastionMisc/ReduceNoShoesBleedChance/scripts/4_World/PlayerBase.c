modded class PlayerBase
{
    override float GetFeetDamageMoveModifier()
    {
        float reducedModifier = super.GetFeetDamageMoveModifier();
        if (reducedModifier) // maybe 0
        {
            return (reducedModifier * 0.05);
        }
        return reducedModifier;
    }
}