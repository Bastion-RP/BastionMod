/* class ModdedCURL : CURLCallback
{
	ref array< Class > oof = new array< Class >;
	string error;

	override void OnSuccess( string data, int dataSize )
	{
		JsonSerializer json = new JsonSerializer();

		json.ReadFromString( oof, data, error );
		oof.Debug();
	}
} */