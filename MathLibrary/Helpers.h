class Vector4;
class Vector3;
class Vector2;

class Matrix4x4;
class Matrix3x3;
class Matrix2x2;

namespace HELPERS
{
	#define PI 3.141592653589793

	float Deg2Rad(float _degrees);
	float Rad2Deg(float _radians);

	Matrix3x3 FindSubMatrix4x4(Matrix4x4 _mat, int _row, int _col);
	float FindCofactor4x4(Matrix4x4 _mat, int _row, int _col);
	Matrix4x4 FindCofactorMatrix4x4(Matrix4x4 _mat);

	Matrix2x2 FindSubMatrix3x3(Matrix3x3 _mat, int _row, int _col);
	float FindCofactor3x3(Matrix3x3 _mat, int _row, int _col);
	Matrix3x3 FindCofactorMatrix3x3(Matrix3x3 _mat);
}