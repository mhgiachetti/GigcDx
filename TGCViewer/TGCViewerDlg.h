// TGCViewerDlg.h : header file
//

#if !defined(AFX_TGCVIEWERDLG_H__5512B143_4F70_46EA_AC44_BED33896540C__INCLUDED_)
#define AFX_TGCVIEWERDLG_H__5512B143_4F70_46EA_AC44_BED33896540C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTGCViewerDlg dialog

class CTGCViewerDlg : public CDialog
{
// Construction
public:
	CTGCViewerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTGCViewerDlg)
	enum { IDD = IDD_TGCVIEWER_DIALOG };
	CStatic	m_panel3d;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTGCViewerDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HACCEL  m_hAccelTable;

	// Generated message map functions
	//{{AFX_MSG(CTGCViewerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnVerWireframe();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TGCVIEWERDLG_H__5512B143_4F70_46EA_AC44_BED33896540C__INCLUDED_)
