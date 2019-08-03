// lineclip.h : main header file for the LINECLIP application
//

#if !defined(AFX_LINECLIP_H__2F35E297_40DF_49C7_B2E3_1C1714105233__INCLUDED_)
#define AFX_LINECLIP_H__2F35E297_40DF_49C7_B2E3_1C1714105233__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLineclipApp:
// See lineclip.cpp for the implementation of this class
//

class CLineclipApp : public CWinApp
{
public:
	CLineclipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineclipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLineclipApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECLIP_H__2F35E297_40DF_49C7_B2E3_1C1714105233__INCLUDED_)
