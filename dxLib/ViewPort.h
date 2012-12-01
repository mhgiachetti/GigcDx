// Viewport.h: interface for the Viewport class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWPORT_H__23EB583E_886E_4A75_84F2_78B73D39D414__INCLUDED_)
#define AFX_VIEWPORT_H__23EB583E_886E_4A75_84F2_78B73D39D414__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"

class Viewport : public D3DVIEWPORT 
{
public:
	Viewport();
	~Viewport();

	operator D3DVIEWPORT()const;
	operator D3DVIEWPORT*()const;

};

#endif // !defined(AFX_VIEWPORT_H__23EB583E_886E_4A75_84F2_78B73D39D414__INCLUDED_)
