; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLeftPortion
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TransformPrg.h"
LastPage=0

ClassCount=6
Class1=CTransformPrgApp
Class2=CTransformPrgDoc
Class3=CTransformPrgView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CLeftPortion
Resource3=IDD_DIALOG1

[CLS:CTransformPrgApp]
Type=0
HeaderFile=TransformPrg.h
ImplementationFile=TransformPrg.cpp
Filter=N

[CLS:CTransformPrgDoc]
Type=0
HeaderFile=TransformPrgDoc.h
ImplementationFile=TransformPrgDoc.cpp
Filter=N

[CLS:CTransformPrgView]
Type=0
HeaderFile=TransformPrgView.h
ImplementationFile=TransformPrgView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CTransformPrgView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=TransformPrg.cpp
ImplementationFile=TransformPrg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIALOG1]
Type=1
Class=CLeftPortion
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_SLIDER1,msctls_trackbar32,1342242825
Control6=IDC_SLIDER2,msctls_trackbar32,1342242825
Control7=IDC_SLIDER3,msctls_trackbar32,1342242825
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_SLIDER4,msctls_trackbar32,1342242825
Control11=IDC_SLIDER5,msctls_trackbar32,1342242825
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CURFACE,static,1342308352

[CLS:CLeftPortion]
Type=0
HeaderFile=LeftPortion.h
ImplementationFile=LeftPortion.cpp
BaseClass=CFormView
Filter=D
VirtualFilter=VWC
LastObject=CLeftPortion

