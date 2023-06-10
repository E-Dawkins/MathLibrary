class Vector4;
class Vector3;
class Vector2;

class Matrix4x4;
class Matrix3x3;
class Matrix2x2;

namespace HELPERS
{
	#define PI 3.14159265358979323846
	#define EPS 1e-7

	float Deg2Rad(float _degrees);
	float Rad2Deg(float _radians);

	Matrix3x3 FindSubMatrix4x4(Matrix4x4 _mat, int _row, int _col);
	float FindCofactor4x4(Matrix4x4 _mat, int _row, int _col);
	Matrix4x4 FindCofactorMatrix4x4(Matrix4x4 _mat);

	Matrix2x2 FindSubMatrix3x3(Matrix3x3 _mat, int _row, int _col);
	float FindCofactor3x3(Matrix3x3 _mat, int _row, int _col);
	Matrix3x3 FindCofactorMatrix3x3(Matrix3x3 _mat);

	float Clamp(float _value, float _min, float _max);
	double Clamp(double _value, double _min, double _max);
	int Clamp(int _value, int _min, int _max);
}