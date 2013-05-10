; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRegexHelperDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RegexHelper.h"

ClassCount=3
Class1=CRegexHelperApp
Class2=CRegexHelperDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDR_MNUREGEX
Resource4=IDD_DLG_REGEXHELPER

[CLS:CRegexHelperApp]
Type=0
HeaderFile=RegexHelper.h
ImplementationFile=RegexHelper.cpp
Filter=N

[CLS:CRegexHelperDlg]
Type=0
HeaderFile=RegexHelperDlg.h
ImplementationFile=RegexHelperDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=ID_MNUREGEXDATE

[CLS:CAboutDlg]
Type=0
HeaderFile=RegexHelperDlg.h
ImplementationFile=RegexHelperDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DLG_REGEXHELPER]
Type=1
Class=CRegexHelperDlg
ControlCount=9
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDTPATTERN,edit,1350631492
Control4=IDC_EDTLOG,edit,1350631492
Control5=IDC_EDTRESULT,edit,1350631492
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BTNINSERT,button,1342242816
Control8=IDC_BTNMATCH,button,1342242816
Control9=IDC_STATIC,static,1342308352

[MNU:IDR_MNUREGEX]
Type=1
Class=?
Command1=ID_MNUREGEXFIND
Command2=ID_MNUREGEXIP
Command3=ID_MNUREGEXDATE
Command4=ID_MNUREGEXSTR
Command5=ID_MNUREGEXNUM
CommandCount=5

