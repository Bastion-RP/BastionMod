class NewsData
{
    protected string title;
    protected string link;

    void NewsData( string _title = "", string _link = "" )
    {
        title = _title;
        link = _link;
    }

    string GetTitle() { return title; }
    string GetLink() { return link; }
}