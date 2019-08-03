; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "open.h"
LastPage=0

ClassCount=8
Class1=COpenApp
Class2=COpenDoc
Class3=COpenView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_DIALOG1
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=IDTRANSDLG
Resource3=IDD_ABOUTBOX
Class7=CScaleDlg
Resource4=IDD_DIALOG2
Class8=CRotateDlg
Resource5=IDD_DIALOG3

[CLS:COpenApp]
Type=0
HeaderFile=open.h
ImplementationFile=open.cpp
Filter=N

[CLS:COpenDoc]
Type=0
HeaderFile=openDoc.h
ImplementationFile=openDoc.cpp
Filter=N

[CLS:COpenView]
Type=0
HeaderFile=openView.h
ImplementationFile=openView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=COpenView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_FANLI1




[CLS:CAboutDlg]
Type=0
HeaderFile=open.cpp
ImplementationFile=open.cpp
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
Command17=IDM_TRANSFORM
Command18=IDM_RO
Command19=IDM_SCALE
Command20=IDM_FUHE
Command21=IDM_FANLI
CommandCount=21

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
Class=IDTRANSDLG
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552

[CLS:IDTRANSDLG]
Type=0
HeaderFile=IDTRANSDLG.h
ImplementationFile=IDTRANSDLG.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=ID_APP_ABOUT

[DLG:IDD_DIALOG2]
Type=1
Class=CScaleDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_EDIT2,edit,1350631552
Control8=IDC_EDIT3,edit,1350631552

[CLS:CScaleDlg]
Type=0
HeaderFile=ScaleDlg.h
ImplementationFile=ScaleDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CScaleDlg

[DLG:IDD_DIALOG3]
Type=1
Class=CRotateDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_EDIT2,edit,1350631552
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_EDIT4,edit,1350631552

[CLS:CRotateDlg]
Type=0
HeaderFile=RotateDlg.h
ImplementationFile=RotateDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CRotateDlg

