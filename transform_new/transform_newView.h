// transform_newView.h : interface of the CTransform_newView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSFORM_NEWVIEW_H__62E81195_EF23_4213_8C40_99E4647F329E__INCLUDED_)
#define AFX_TRANSFORM_NEWVIEW_H__62E81195_EF23_4213_8C40_99E4647F329E__INCLUDED_

#include "Transform.h"	// Added by ClassView
#include "P2.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransform_newView : public CView
{
protected: // create from serialization only
	CTransform_newView();
	DECLARE_DYNCREATE(CTransform_newView)

// Attributes
public:
	CTransform_newDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransform_newView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	CRect rect;
	void DrawObject(CDC *pDC);
	void DoubleBuffer();
	void drawPoly(CDC *pDC);
	void initRect();
	CP2 points[4];
	CTransform transform;
	virtual ~CTransform_newView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTransform_newView)
	afx_msg void OnLeft();
	afx_msg void OnRefresh();
	afx_msg void OnRight();
	afx_msg void OnDown();
	afx_msg void OnReflectorg();
	afx_msg void OnReflectx();
	afx_msg void OnReflecty();
	afx_msg void OnRotateleft();
	afx_msg void OnRotateright();
	afx_msg void OnScaledown();
	afx_msg void OnScaleup();
	afx_msg void OnSheardown();
	afx_msg void OnShearleft();
	afx_msg void OnShearright();
	afx_msg void OnShearup();
	afx_msg void OnUp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in transform_newView.cpp
inline CTransform_newDoc* CTransform_newView::GetDocument()
   { return (CTransform_newDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORM_NEWVIEW_H__62E81195_EF23_4213_8C40_99E4647F329E__INCLUDED_)
