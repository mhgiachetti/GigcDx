// IntMatrix.h: interface for the IntMatrix class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_INTMATRIX_H__2A08CB6F_D97B_4482_8C0C_6F1D34AC44F4__INCLUDED_)
#define AFX_INTMATRIX_H__2A08CB6F_D97B_4482_8C0C_6F1D34AC44F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../dxLib/dxLib.h"

class IntMatrix  
{
public:
	int * m_data;
	int m_width;
	int m_height;

public:
	IntMatrix();
	virtual ~IntMatrix();
	void Resize(int width, int height);
	int GetLength(int dimension);

	int GetItem(int i, int j);
	void SetItem(int i, int j, int value);
};

#endif // !defined(AFX_INTMATRIX_H__2A08CB6F_D97B_4482_8C0C_6F1D34AC44F4__INCLUDED_)
