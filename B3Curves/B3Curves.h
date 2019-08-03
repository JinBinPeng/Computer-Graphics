// B3Curves.h : main header file for the B3CURVES application
//

#if !defined(AFX_B3CURVES_H__7E269822_72C0_47ED_9196_BDF6638175BF__INCLUDED_)
#define AFX_B3CURVES_H__7E269822_72C0_47ED_9196_BDF6638175BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesApp:
// See B3Curves.cpp for the implementation of this class
//

class CB3CurvesApp : public CWinApp
{
public:
	CB3CurvesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB3CurvesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CB3CurvesApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B3CURVES_H__7E269822_72C0_47ED_9196_BDF6638175BF__INCLUDED_)
