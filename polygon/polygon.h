// polygon.h : main header file for the POLYGON application
//

#if !defined(AFX_POLYGON_H__6ABCAB0F_D825_459A_AEEB_1BFFB198DA8E__INCLUDED_)
#define AFX_POLYGON_H__6ABCAB0F_D825_459A_AEEB_1BFFB198DA8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPolygonApp:
// See polygon.cpp for the implementation of this class
//

class CPolygonApp : public CWinApp
{
public:
	CPolygonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolygonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPolygonApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGON_H__6ABCAB0F_D825_459A_AEEB_1BFFB198DA8E__INCLUDED_)
