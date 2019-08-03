// Koch.h : main header file for the KOCH application
//

#if !defined(AFX_KOCH_H__BA6AE677_0D66_4E23_ABD5_8F98611934A6__INCLUDED_)
#define AFX_KOCH_H__BA6AE677_0D66_4E23_ABD5_8F98611934A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CKochApp:
// See Koch.cpp for the implementation of this class
//

class CKochApp : public CWinApp
{
public:
	CKochApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKochApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CKochApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOCH_H__BA6AE677_0D66_4E23_ABD5_8F98611934A6__INCLUDED_)
