; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTransform_newView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "transform_new.h"
LastPage=0

ClassCount=5
Class1=CTransform_newApp
Class2=CTransform_newDoc
Class3=CTransform_newView
Class4=CMainFrame

ResourceCount=2
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX

[CLS:CTransform_newApp]
Type=0
HeaderFile=transform_new.h
ImplementationFile=transform_new.cpp
Filter=N

[CLS:CTransform_newDoc]
Type=0
HeaderFile=transform_newDoc.h
ImplementationFile=transform_newDoc.cpp
Filter=N

[CLS:CTransform_newView]
Type=0
HeaderFile=transform_newView.h
ImplementationFile=transform_newView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDB_UP


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDB_SHEARDOWN




[CLS:CAboutDlg]
Type=0
HeaderFile=transform_new.cpp
ImplementationFile=transform_new.cpp
Filter=D

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
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_APP_ABOUT
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=IDB_REFRESH
Command2=IDB_LEFT
Command3=IDB_RIGHT
Command4=IDB_UP
Command5=IDB_DOWN
Command6=IDB_SCALEUP
Command7=IDB_SCALEDOWN
Command8=IDB_ROTATELEFT
Command9=IDB_ROTATERIGHT
Command10=IDB_REFLECTX
Command11=IDB_REFLECTY
Command12=IDB_REFLECTORG
Command13=IDB_SHEARRIGHT
Command14=IDB_SHEARLEFT
Command15=IDB_SHEARUP
Command16=IDB_SHEARDOWN
CommandCount=16

