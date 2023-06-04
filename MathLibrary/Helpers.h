#define PI 3.141592653589793

static float Deg2Rad(float _degrees)
{
	return _degrees * ((float)PI / 180.f);
}

static float Rad2Deg(float _radians)
{
	return _radians * (180.f / (float)PI);
}