// RegexHelperDlg.h : header file
//

#include "afxwin.h"
#if !defined(AFX_REGEXHELPERDLG_H__6E2864D7_8A2D_462B_81B9_9D3BDA4582B7__INCLUDED_)
#define AFX_REGEXHELPERDLG_H__6E2864D7_8A2D_462B_81B9_9D3BDA4582B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CRegexHelperDlg dialog

class CRegexHelperDlg : public CDialog
{
// Construction
public:
	CRegexHelperDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CRegexHelperDlg)
	enum { IDD = IDD_DLG_REGEXHELPER };
	CString	m_Log;
	CString	m_Pattern;
	CString	m_Result;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegexHelperDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CRegexHelperDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtninsert();
	afx_msg void OnBtnmatch();
	afx_msg void OnMnuregexstr();
	afx_msg void OnMnuregexnum();
	afx_msg void OnMnuregexip();
	afx_msg void OnMnuregexfind();
	afx_msg void OnMnuregexdate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_edtRegex;
	int InsertStringToEdit(CString str);
	afx_msg void OnMnuregexstr2();
	afx_msg void OnBnClickedBtnmake();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGEXHELPERDLG_H__6E2864D7_8A2D_462B_81B9_9D3BDA4582B7__INCLUDED_)
