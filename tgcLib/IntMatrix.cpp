// IntMatrix.cpp: implementation of the IntMatrix class.
//
//////////////////////////////////////////////////////////////////////

#include "IntMatrix.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IntMatrix::IntMatrix()
{
	m_data = NULL;
}

IntMatrix::~IntMatrix()
{
	if(m_data)
		delete [] m_data;

}

void IntMatrix::Resize( int width, int height )
{
	m_width = width;
	m_height = height;
	m_data = new int [width*height];
}

int IntMatrix::GetLength( int dimension )
{
	return dimension == 0? m_width:m_height;
}

int IntMatrix::GetItem( int i, int j )
{
	return m_data[j*m_width + i];
}

void IntMatrix::SetItem( int i, int j, int value )
{
	m_data[j*m_width + i] = value;
}
