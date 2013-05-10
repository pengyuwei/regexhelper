// RegexHelperDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RegexHelper.h"
#include "RegexHelperDlg.h"
#include "regexpr2.h"
#include ".\regexhelperdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegexHelperDlg dialog

CRegexHelperDlg::CRegexHelperDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRegexHelperDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRegexHelperDlg)
	m_Log = _T("a=1;b=bb;c=600;d=are you;");
	m_Pattern = _T("");
	m_Result = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRegexHelperDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegexHelperDlg)
	DDX_Text(pDX, IDC_EDTLOG, m_Log);
	DDX_Text(pDX, IDC_EDTPATTERN, m_Pattern);
	DDX_Text(pDX, IDC_EDTRESULT, m_Result);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDTPATTERN, m_edtRegex);
}

BEGIN_MESSAGE_MAP(CRegexHelperDlg, CDialog)
	//{{AFX_MSG_MAP(CRegexHelperDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNINSERT, OnBtninsert)
	ON_BN_CLICKED(IDC_BTNMATCH, OnBtnmatch)
	ON_COMMAND(ID_MNUREGEXSTR, OnMnuregexstr)
	ON_COMMAND(ID_MNUREGEXNUM, OnMnuregexnum)
	ON_COMMAND(ID_MNUREGEXIP, OnMnuregexip)
	ON_COMMAND(ID_MNUREGEXFIND, OnMnuregexfind)
	ON_COMMAND(ID_MNUREGEXDATE, OnMnuregexdate)
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_MNUREGEXSTR2, OnMnuregexstr2)
	ON_BN_CLICKED(IDC_BTNMAKE, OnBnClickedBtnmake)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegexHelperDlg message handlers

BOOL CRegexHelperDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRegexHelperDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRegexHelperDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRegexHelperDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CRegexHelperDlg::OnBtninsert() 
{
	// TODO: Add your control notification handler code here
	CPoint pt;
	GetCursorPos(&pt);
	const int MENUINDEX_REGEX=0;
	CMenu menu; 
	menu.LoadMenu(IDR_MNUREGEX);
	CMenu* pMnu=(CMenu *)menu.GetSubMenu(MENUINDEX_REGEX);//元件菜单
	
	pMnu->TrackPopupMenu(TPM_LEFTALIGN,pt.x,pt.y,this);
}

void CRegexHelperDlg::OnBtnmatch() 
{
	
	if (!UpdateData())
	{
		return;
	}
	
	m_Result="";
	
	try
	{
		//执行正则表达式
		Global::EnumStrings strRets;
		Global::Func::MultiMatch((char *)(LPCSTR)m_Pattern, (char *)(LPCTSTR)m_Log, strRets);

		m_Result = "";
		Global::EnumStrings::iterator itor;
		for (itor=strRets.begin();itor!=strRets.end();itor++)
		{
			m_Result += (*itor).c_str();
			m_Result += "\r\n";
		}

		//regex::match_results *results = new regex::match_results();
 	//	regex::match_results::backref_type *br = new regex::match_results::backref_type();

		//regex::rpattern *pat = new regex::rpattern((char *)(LPCSTR)m_Pattern);
 	//	*br = pat->match((char *)(LPCTSTR)m_Log, *results);
 	//	
 	//
 	//	if (br->matched)
 	//	{
 	//		m_Result.Format("%s",br->str().c_str());
 	//	}
 	//	delete pat;
 	//	delete br;
 	//	delete results;
	}
	catch (...) 
	{
		AfxMessageBox("匹配出错");
	}
	
	UpdateData(FALSE);
}

void CRegexHelperDlg::OnMnuregexstr() 
{
	if (!UpdateData())
	{
		return;
	}

	InsertStringToEdit("(\\S+)");
	UpdateData(FALSE);	
	
}

void CRegexHelperDlg::OnMnuregexnum() 
{
	if (!UpdateData())
	{
		return;
	}

	InsertStringToEdit("(\\d+)");
	UpdateData(FALSE);
	
}

void CRegexHelperDlg::OnMnuregexip() 
{
	if (!UpdateData())
	{
		return;
	}

	InsertStringToEdit("(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})");
	UpdateData(FALSE);
	
}

void CRegexHelperDlg::OnMnuregexfind() 
{
	if (!UpdateData())
	{
		return;
	}
	InsertStringToEdit("(?<=)");

	UpdateData(FALSE);	
	
}

void CRegexHelperDlg::OnMnuregexdate() 
{
	if (!UpdateData())
	{
		return;
	}

	InsertStringToEdit("(\\d{4}\\-\\d+\\-\\d+\\s\\d+\\:\\d+\\:\\d+)");

	UpdateData(FALSE);
	
}

int CRegexHelperDlg::InsertStringToEdit(CString str)
{
	CPoint ptCurrent;
	ptCurrent = GetCaretPos();

	int n = m_edtRegex.CharFromPos(ptCurrent);
	int nLineIndex = HIWORD(n);
	int nCharIndex = LOWORD(n);

	m_Pattern = m_Pattern.Left(nCharIndex) 
		+ str
		+ m_Pattern.Right(m_Pattern.GetLength()-nCharIndex);

	return 0;
}

void CRegexHelperDlg::OnMnuregexstr2()
{
	if (!UpdateData())
	{
		return;
	}

	InsertStringToEdit("(.*?)" );

	UpdateData(FALSE);
}

void CRegexHelperDlg::OnBnClickedBtnmake()
{
	if (!UpdateData())
	{
		return;
	}

	try
	{
		m_Pattern = CHelper::AutoMakeRegex((LPCSTR)m_Log).c_str();
	}
	catch(...)
	{
		m_Pattern = "看不懂～";
	}

	UpdateData(FALSE);
}
