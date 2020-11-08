class GpsData
{
	float x, y, scale;
	void SetData(array<float> arr)
	{
		x = arr[0];
		y = arr[1];
		scale = arr[2];
	}
}