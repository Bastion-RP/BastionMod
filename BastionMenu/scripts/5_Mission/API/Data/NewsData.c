class NewsData
{
    protected string post_id;
    protected string link_title;
    protected string title;

    void NewsData( string _post_id = "", string _link_title = "", string _title = "" )
    {
        post_id = _post_id;
        link_title = _link_title;
        title = _title;
    }

    string GetId() { return post_id; }
    string GetLinkTitle() { return link_title; }
    string GetLink() { return "https://bastionrp.com/forums/topic/" + post_id + "-" + link_title; }
    string GetTitle() { return title; }
}