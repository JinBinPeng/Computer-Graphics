// BezierCurve.h : main header file for the BEZIERCURVE application
//

#if !defined(AFX_BEZIERCURVE_H__3B7B31A7_AE62_4799_8A3E_7F1A144D991B__INCLUDED_)
#define AFX_BEZIERCURVE_H__3B7B31A7_AE62_4799_8A3E_7F1A144D991B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveApp:
// See BezierCurve.cpp for the implementation of this class
//

class CBezierCurveApp : public CWinApp
{
public:
	CBezierCurveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBezierCurveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBezierCurveApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEZIERCURVE_H__3B7B31A7_AE62_4799_8A3E_7F1A144D991B__INCLUDED_)
