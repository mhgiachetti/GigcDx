// Vector2.cpp: implementation of the Vector2 class.
//
//////////////////////////////////////////////////////////////////////

#include "Vector2.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Vector2::Vector2()
{

}

Vector2::Vector2( const float * vector)
{
	v[0] = vector[0];
	v[1] = vector[1];
}

Vector2::Vector2( float x, float y )
{
	v[0] = x;
	v[1] = y;
}

Vector2::~Vector2()
{

}
