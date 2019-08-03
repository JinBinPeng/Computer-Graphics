// GraphicFill.h : main header file for the GRAPHICFILL application
//

#if !defined(AFX_GRAPHICFILL_H__4159BAED_7546_4531_8258_0B2E92F0EFB2__INCLUDED_)
#define AFX_GRAPHICFILL_H__4159BAED_7546_4531_8258_0B2E92F0EFB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillApp:
// See GraphicFill.cpp for the implementation of this class
//

class CGraphicFillApp : public CWinApp
{
public:
	CGraphicFillApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphicFillApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CGraphicFillApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHICFILL_H__4159BAED_7546_4531_8258_0B2E92F0EFB2__INCLUDED_)
