// open.h : main header file for the OPEN application
//

#if !defined(AFX_OPEN_H__42EA96E1_8AE4_485C_ACB3_7E85730FEBE4__INCLUDED_)
#define AFX_OPEN_H__42EA96E1_8AE4_485C_ACB3_7E85730FEBE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COpenApp:
// See open.cpp for the implementation of this class
//

class COpenApp : public CWinApp
{
public:
	COpenApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COpenApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPEN_H__42EA96E1_8AE4_485C_ACB3_7E85730FEBE4__INCLUDED_)
