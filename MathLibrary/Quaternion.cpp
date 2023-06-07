#include "pch.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "Matrix4x4.h"

Quaternion Quaternion::identity = Quaternion(0, 0, 0, 1);

Quaternion::Quaternion()
{
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Quaternion::Quaternion(float _x, float _y, float _z, float _w)
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

Quaternion::Quaternion(Vector3 _vector, float _scalar)
{
	x = _vector.x;
	y = _vector.y;
	z = _vector.z;
	w = _scalar;
}

Vector3 Quaternion::Vector()
{
	return Vector3(x, y, z);
}

float& Quaternion::operator[](int _index)
{
	if (_index < 0 || _index > 3)
		throw std::out_of_range("Subscript index was out of range!");

	switch (_index)
	{
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
	}
}

bool Quaternion::operator==(Quaternion _other)
{
	return x == _other.x && y == _other.y && z == _other.z && w == _other.w;
}

bool Quaternion::operator!=(Quaternion _other)
{
	return x != _other.x || y != _other.y || z != _other.z || w != _other.w;
}

Quaternion operator*(Quaternion _lhs, Quaternion _rhs)
{
	float scalar = (_lhs.w * _rhs.w) - (Vector3::Dot(_lhs.Vector(), _rhs.Vector()));
	Vector3 vector = (_lhs.w * _rhs.Vector()) + (_rhs.w * _lhs.Vector()) + Vector3::Cross(_lhs.Vector(), _rhs.Vector());
	return Quaternion(vector, scalar);
}

Quaternion operator*(float _lhs, Quaternion _rhs)
{
	return Quaternion(_rhs.x * _lhs, _rhs.y * _lhs, _rhs.z * _lhs, _rhs.w * _lhs);
}

Quaternion operator*(Quaternion _lhs, float _rhs)
{
	return Quaternion(_lhs.x * _rhs, _lhs.y * _rhs, _lhs.z * _rhs, _lhs.w * _rhs);
}

Quaternion operator+(Quaternion _lhs, Quaternion _rhs)
{
	return Quaternion(_lhs.x + _rhs.x, _lhs.y + _rhs.y, _lhs.z + _rhs.z, _lhs.w + _rhs.w);
}

Quaternion operator-(Quaternion _lhs, Quaternion _rhs)
{
	return Quaternion(_lhs.x - _rhs.x, _lhs.y - _rhs.y, _lhs.z - _rhs.z, _lhs.w - _rhs.w);
}

float Quaternion::Dot(Quaternion _other)
{
	return (w * _other.w) + (x * _other.x) + (y * _other.y) + (z * _other.z);
}

float Quaternion::Dot(Quaternion _a, Quaternion _b)
{
	return (_a.w * _b.w) + (_a.x * _b.x) + (_a.y * _b.y) + (_a.z * _b.z);
}

bool Quaternion::IsIdentity()
{
	return x == 0 && y == 0 && z == 0 && w == 1;
}

bool Quaternion::IsIdentity(Quaternion _quat)
{
	return _quat == Quaternion(0, 0, 0, 1);
}

float Quaternion::Magnitude()
{
	return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
}

float Quaternion::Magnitude(Quaternion _quat)
{
	return sqrtf((_quat.x * _quat.x) + (_quat.y * _quat.y)
		+ (_quat.z * _quat.z) + (_quat.w * _quat.w));
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(-x, -y, -z, w);
}

Quaternion Quaternion::Conjugate(Quaternion _quat)
{
	return Quaternion(-_quat.x, -_quat.y, -_quat.z, _quat.w);
}

Quaternion Quaternion::Lerp(Quaternion _from, Quaternion _to, float _t)
{
	float t = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));

	float x = _from.x + t * (_to.x - _from.x);
	float y = _from.y + t * (_to.y - _from.y);
	float z = _from.z + t * (_to.z - _from.z);
	float w = _from.w + t * (_to.w - _from.w);

	return Quaternion(x, y, z, w);
}

Quaternion Quaternion::Slerp(Quaternion _from, Quaternion _to, float _t)
{
	float t = (_t < 0 ? 0 : (_t > 1 ? 1 : _t));

	float dot = Dot(_from, _to);

	if (abs(dot) >= 1.f)
		return _from;

	float angle = acosf(dot);
	float sinAngle = sqrtf(1.f - (dot * dot));

	if (fabsf(sinAngle) < 0.001f)
	{
		return Quaternion
		(
			_from.x * 0.5f + _to.x * 0.5f,
			_from.y * 0.5f + _to.y * 0.5f,
			_from.z * 0.5f + _to.z * 0.5f,
			_from.w * 0.5f + _to.w * 0.5f
		);
	}

	float ratioA = sinf((1.f - t) * angle) / sinAngle;
	float ratioB = sinf(t * angle) / sinAngle;

	return Quaternion
	(
		_from.x * ratioA + _to.x * ratioB,
		_from.y * ratioA + _to.y * ratioB,
		_from.z * ratioA + _to.z * ratioB,
		_from.w * ratioA + _to.w * ratioB
	);
}

void operator<<(std::ostream& _os, Quaternion& _quat)
{
	_os << "(" << _quat.x << ", " << _quat.y << ", " << _quat.z << ", " << _quat.w << ")";
}
