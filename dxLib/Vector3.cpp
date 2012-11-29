// Vector3.cpp: implementation of the Vector3 class.
//
//////////////////////////////////////////////////////////////////////

#include "Vector3.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Vector3::Vector3()
{
	ZeroMemory(v,sizeof(v));
}

Vector3::Vector3( const float * v2)
{
	memcpy(v,v2,sizeof(v));
}

Vector3::Vector3( float x, float y, float z )
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
}

Vector3::~Vector3()
{

}

Vector3::operator float*()
{
	return (float*)v;
}

Vector3::operator const float*() const
{
	return (const float*)v;
}

Vector3& Vector3::operator+=( const Vector3& v2)
{
	v[0] += v2.x;
	v[1] += v2.y;
	v[2] += v2.z;

	return (*this);
}

Vector3& Vector3::operator-=( const Vector3& v2)
{
	v[0] -= v2.x;
	v[1] -= v2.y;
	v[2] -= v2.z;
	
	return (*this);
}

Vector3& Vector3::operator*=( float val)
{
	v[0] *= val;
	v[1] *= val;
	v[2] *= val;
	
	return (*this);
}

Vector3& Vector3::operator/=( float val)
{
	v[0] /= val;
	v[1] /= val;
	v[2] /= val;
	
	return (*this);
}

Vector3 Vector3::operator-( const Vector3& v2) const
{
	return Vector3(v[0] - v2.x, v[1] - v2.y, v[2] - v2.z);
}

Vector3 Vector3::operator*( float val) const
{
	return Vector3(x*val, y*val, z*val);
}

Vector3 Vector3::operator/( float val) const
{
	return Vector3(x/val, y/val, z/val);
}

bool Vector3::operator==( const Vector3& v2) const
{
	return x==v2.x && y==v2.y && z==v2.z;
}

bool Vector3::operator!=( const Vector3& v2) const
{
	return !((*this) == v2);
}

float Vector3::Dot( const Vector3 &v ) const
{
	return Vector3::Dot((*this), v);
}

Vector3 Vector3::Cross( const Vector3 &v ) const
{
	return Vector3::Cross((*this), v);
}

float Vector3::LengthSq() const
{
	return x*x + y*y + z*z;
}

float Vector3::Length() const
{
	return (float)sqrt(LengthSq());
}

float Vector3::Normalize()
{
	float len = Length();
	(*this) /= len;
	return len;
}

//Static functions
float Vector3::Dot( const Vector3 &v1, const Vector3 &v2 )
{
	return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

Vector3 Vector3::Cross( const Vector3 &v1, const Vector3 &v2 )
{
	return Vector3(
		v1.y*v2.z - v1.z*v2.y,
		v1.z*v2.x - v1.x*v2.z,
		v1.x*v2.y - v1.y*v2.x
		);
}


Vector3 Vector3::Normalize( const Vector3 &v )
{
	return v/v.Length();
}

Vector3::operator D3DXVECTOR3*() const
{
	return (D3DXVECTOR3*)this;
}




