// transform_new.h : main header file for the TRANSFORM_NEW application
//

#if !defined(AFX_TRANSFORM_NEW_H__2064E6DB_BC80_4A32_B360_AB9E7B22DEBA__INCLUDED_)
#define AFX_TRANSFORM_NEW_H__2064E6DB_BC80_4A32_B360_AB9E7B22DEBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransform_newApp:
// See transform_new.cpp for the implementation of this class
//

class CTransform_newApp : public CWinApp
{
public:
	CTransform_newApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransform_newApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTransform_newApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORM_NEW_H__2064E6DB_BC80_4A32_B360_AB9E7B22DEBA__INCLUDED_)
