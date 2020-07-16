class HackHouseToolBase : ItemBook
{
    private float   m_ChanceHacking;
    private int     m_TimeHacking;

    void HackHouseToolBase()
    {
        SetChanceHacking(0.5); //default 50%;
        SetTimeHacking(20); // 30 secs
    }

    float GetChanceHacking()
    {
        return m_ChanceHacking;
    }

    int GetTimeHacking()
    {
        return m_TimeHacking;
    }

    void SetChanceHacking(float chance)
    {
        m_ChanceHacking = chance;
    }

    void SetTimeHacking(int time) // in sec
    {
        m_TimeHacking = time;
    }

    bool RollHackDoor()
    {
        if( Math.RandomFloat01() < GetChanceHacking() )
        {
            return true;
        }
        return false;
    }

    bool RollHack(float chance)
    {
        if( Math.RandomFloat01() < chance )
        {
            return true;
        }
        return false;
    }

    void Destroy()
    {
        this.Delete();
    }

    void HackFailed(Object obj)
    {
        GetGame().CreateObject("SirenProp", obj.GetPosition());
    }

    override void SetActions()
	{
		super.SetActions();
        AddAction(ActionHackBRPDoor);
        AddAction(ActionHackISFWeapon);
    }
}

class BRP_HackingTool : HackHouseToolBase
{
    void BRP_HackingTool()
    {
        SetChanceHacking(0.5);
        SetTimeHacking(30);
    }
}