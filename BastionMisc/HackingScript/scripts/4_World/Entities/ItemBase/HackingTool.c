class HackHouseToolBase : ItemBook
{
    private float           m_ChanceHacking;
    private int             m_TimeHacking;
    private ref array<int>  m_AllowClasses;
    private bool            m_CanBeDestroyed;

    void HackHouseToolBase()
    {
        m_AllowClasses = new array<int>();

        SetChanceHacking(0.5); //default 50%;
        SetTimeHacking(20); // 20 secs
        SetCanDestroyed(true);
    }

    float GetChanceHacking()
    {
        return m_ChanceHacking;
    }

    int GetTimeHacking()
    {
        return m_TimeHacking;
    }

    bool CanBeDestroyed()
    {
        return m_CanBeDestroyed;
    }

    void SetAllowClasses(array<int> arr)
    {
        m_AllowClasses = arr;
    }

    void SetChanceHacking(float chance)
    {
        m_ChanceHacking = chance;
    }

    void SetCanDestroyed(bool val)
    {
        m_CanBeDestroyed = val;
    }

    void SetTimeHacking(int time) // in sec
    {
        m_TimeHacking = time;
    }

    bool RollHackDoor()
    {
        if( Math.RandomFloat01() <= GetChanceHacking() )
        {
            return true;
        }
        return false;
    }

    bool RollHack(float chance)
    {
        if( Math.RandomFloat01() <= chance )
        {
            return true;
        }
        return false;
    }

    bool CheckPlayerClass(int multiClass)
    {
        if ( m_AllowClasses.Count() == 0 )
            return true;
        return ( m_AllowClasses.Find(multiClass) >= 0 );
    }

    void Destroy()
    {
        if (CanBeDestroyed())
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
        SetCanDestroyed(true);
    }
}

class BRP_HackingTool_Spec : HackHouseToolBase
{
    void BRP_HackingTool_Spec()
    {
        array<int> allowClasses = {5, 6, 7, 8, 9, 10, 11};
        SetChanceHacking(1);
        SetTimeHacking(5);
        SetCanDestroyed(false);
        SetAllowClasses(allowClasses);
    }
}