// Vector3.h: interface for the Vector3 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR3_H__6DE87F63_FD6D_4485_A005_5E7177B55C2F__INCLUDED_)
#define AFX_VECTOR3_H__6DE87F63_FD6D_4485_A005_5E7177B55C2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"

struct Vector3  
{

public:
	union
	{
		struct
		{
			float X,Y,Z;
		};
		float v[3];
	};

public:
	~Vector3();

	Vector3();
    Vector3( const float * );
    //Vector3( const D3DVECTOR& );
    //Vector3( const D3DXFLOAT16 * );
    Vector3( float x, float y, float z );
	

	//static functions
	static float Dot(const Vector3 &v1, const Vector3 &v2);
	static Vector3 Cross(const Vector3 &v1, const Vector3 &v2);
	static Vector3 Normalize(const Vector3 &v);
	
	
	float Dot(const Vector3 &v) const;
	Vector3 Cross(const Vector3 &v) const;
	float LengthSq() const;
	float Length() const;
	float Normalize();


    // casting
    operator float* ();
    operator const float* () const;
	
    // assignment operators
    Vector3& operator += ( const Vector3& );
    Vector3& operator -= ( const Vector3& );
    Vector3& operator *= ( float );
    Vector3& operator /= ( float );
	
    // unary operators
    Vector3 operator + () const;
    Vector3 operator - () const;
	
    // binary operators
    Vector3 operator + ( const Vector3& ) const;
    Vector3 operator - ( const Vector3& ) const;
    Vector3 operator * ( float ) const;
    Vector3 operator / ( float ) const;
	
    friend Vector3 operator * ( float, const Vector3& );
	
    bool operator == ( const Vector3& ) const;
    bool operator != ( const Vector3& ) const;

	operator D3DXVECTOR3*()const;


};

#endif // !defined(AFX_MGVECTOR3_H__6DE87F63_FD6D_4485_A005_5E7177B55C2F__INCLUDED_)
