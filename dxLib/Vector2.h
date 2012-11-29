// Vector2.h: interface for the Vector2 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR2_H__921B7AD0_719A_4BA0_AEFC_AEB629AD5797__INCLUDED_)
#define AFX_VECTOR2_H__921B7AD0_719A_4BA0_AEFC_AEB629AD5797__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

struct Vector2  
{
public:
	union
	{
		struct
		{
			float X,Y;
		};
		float v[2];
	};
public:
	Vector2();
	Vector2( const float * vector);
	Vector2( float x, float y);
	~Vector2();

    
    

};

#endif // !defined(AFX_VECTOR2_H__921B7AD0_719A_4BA0_AEFC_AEB629AD5797__INCLUDED_)
