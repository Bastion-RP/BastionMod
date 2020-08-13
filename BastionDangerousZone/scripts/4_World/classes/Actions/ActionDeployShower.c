class ActionDeployShowerCB : ActionPlaceObjectCB
{
    override void CreateActionComponent() {
        m_ActionData.m_ActionComponent = new CAContinuousTime(15); //Set your time here
    }
}

class ActionDeployShower: ActionPlaceObject
{
    void ActionPlaceObject()
    {
        m_CallbackClass        = ActionDeployShowerCB; //Activating your callback with the custom time
    }
    override bool HasProgress()
    {
        return true;
    }
    override string GetText()
    {
        return "Place Shower";
    }
}
