// RegexHelper.h : main header file for the REGEXHELPER application
//

#if !defined(AFX_REGEXHELPER_H__9CA1C552_C0AF_42C5_B793_2582A2F4E52D__INCLUDED_)
#define AFX_REGEXHELPER_H__9CA1C552_C0AF_42C5_B793_2582A2F4E52D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRegexHelperApp:
// See RegexHelper.cpp for the implementation of this class
//

class CRegexHelperApp : public CWinApp
{
public:
	CRegexHelperApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRegexHelperApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRegexHelperApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REGEXHELPER_H__9CA1C552_C0AF_42C5_B793_2582A2F4E52D__INCLUDED_)
