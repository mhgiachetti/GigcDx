// Vector4.h: interface for the Vector4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR4_H__77E19076_FE6E_44C2_A9B3_B11600C044B0__INCLUDED_)
#define AFX_VECTOR4_H__77E19076_FE6E_44C2_A9B3_B11600C044B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <d3dx9math.h>

class Vector4  
{
	union
	{
		struct
		{
			float X,Y,Z,W;
		};
		float v[4];
	};
public:
	~Vector4();
	Vector4();
    Vector4( float x, float y, float z, float w );
	
    // casting
    operator float* ();
    operator const float* () const;
	
    // assignment operators
    Vector4& operator += ( const Vector4& v2);
    Vector4& operator -= ( const Vector4& v2);
    Vector4& operator *= ( float val);
    Vector4& operator /= ( float val);
	
    // unary operators
    Vector4 operator + () const;
    Vector4 operator - () const;
	
    // binary operators
    Vector4 operator + ( const Vector4& v2) const;
    Vector4 operator - ( const Vector4& v2) const;
    Vector4 operator * ( float val) const;
    Vector4 operator / ( float val) const;
	
    friend Vector4 operator * ( float, const Vector4& );
	
    bool operator == ( const Vector4& v2) const;
    bool operator != ( const Vector4& v2) const;


};

#endif // !defined(AFX_VECTOR4_H__77E19076_FE6E_44C2_A9B3_B11600C044B0__INCLUDED_)
