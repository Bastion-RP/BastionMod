class HackHouseToolBase : ItemBase
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

    void Destroy()
    {
        this.Delete();
    }

    void HackFailed(Object house)
    {
        GetGame().CreateObject("SirenProp", house.GetPosition());
    }

    override void SetActions()
	{
		super.SetActions();
        RemoveAction(ActionLockDoors);
        RemoveAction(ActionUnlockDoors);
        AddAction(ActionHackBRPDoor);
    }
}

class BRP_HackingTool : HackHouseToolBase
{
    void BRP_HackingTool()
    {
        SetChanceHacking(0.5);
        SetTimeHacking(5);
    }
}