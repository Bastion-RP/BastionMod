class OVTGlobalFunctions
{
	static string ConvertToStars( string input )
	{
        string passString = "";

        for (int i = 0; i < input.Length(); i++)
        {
            passString += "*";
        }

        return passString;
	}
}