// PresentParameters.h: interface for the PresentParameters class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PRESENTPARAMETERS_H__A113D261_381D_471B_8569_F3E349A5AA70__INCLUDED_)
#define AFX_PRESENTPARAMETERS_H__A113D261_381D_471B_8569_F3E349A5AA70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "globalDefines.h"

struct PresentParameters  
{
	int					BackBufferWidth;
    int					BackBufferHeight;
    Format				BackBufferFormat;
    int					BackBufferCount;
	
    MultiSampleType		MultiSample;
    int					MultiSampleQuality;
	
    SwapEffect			swapEffect;
    HWND                DeviceWindow;
    bool                Windowed;
    bool                EnableAutoDepthStencil;
    DepthFormat			AutoDepthStencilFormat;
    PresentFlag         presentFlag;
	
    /* FullScreen_RefreshRateInHz must be zero for Windowed mode */
    int					FullScreen_RefreshRateInHz;
    PresentInterval		PresentationInterval;
public:
	PresentParameters();
	~PresentParameters();

	operator D3DPRESENT_PARAMETERS()const;
	operator D3DPRESENT_PARAMETERS*()const;

};

#endif // !defined(AFX_PRESENTPARAMETERS_H__A113D261_381D_471B_8569_F3E349A5AA70__INCLUDED_)
