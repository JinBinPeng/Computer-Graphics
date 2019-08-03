#if !defined(AFX_LEFTPORTION_H__65DA165A_495F_4E26_9D99_14D59DB181F7__INCLUDED_)
#define AFX_LEFTPORTION_H__65DA165A_495F_4E26_9D99_14D59DB181F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LeftPortion.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLeftPortion form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CLeftPortion : public CFormView
{
protected:
	CLeftPortion();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CLeftPortion)

// Form Data
public:
	//{{AFX_DATA(CLeftPortion)
	enum { IDD = IDD_DIALOG1 };
	CSliderCtrl	m_scale;
	CSliderCtrl	m_rotate;
	CSliderCtrl	m_translateY;
	CSliderCtrl	m_translateX;
	CSliderCtrl	m_degree;
	CStatic	m_curface;
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLeftPortion)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CLeftPortion();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CLeftPortion)
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LEFTPORTION_H__65DA165A_495F_4E26_9D99_14D59DB181F7__INCLUDED_)
