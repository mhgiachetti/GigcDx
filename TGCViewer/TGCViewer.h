// TGCViewer.h : main header file for the TGCVIEWER application
//

#if !defined(AFX_TGCVIEWER_H__58A5C2FF_F7AF_45F1_B2DB_CD905E49409D__INCLUDED_)
#define AFX_TGCVIEWER_H__58A5C2FF_F7AF_45F1_B2DB_CD905E49409D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTGCViewerApp:
// See TGCViewer.cpp for the implementation of this class
//

class CTGCViewerApp : public CWinApp
{
public:
	CTGCViewerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTGCViewerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTGCViewerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TGCVIEWER_H__58A5C2FF_F7AF_45F1_B2DB_CD905E49409D__INCLUDED_)
