// TransformPrgView.h : interface of the CTransformPrgView class
//
/////////////////////////////////////////////////////////////////////////////

#include "TransForm.h"
#if !defined(AFX_TRANSFORMPRGVIEW_H__C2B1673D_D039_46B4_AC00_4AC0EF1DD1B8__INCLUDED_)
#define AFX_TRANSFORMPRGVIEW_H__C2B1673D_D039_46B4_AC00_4AC0EF1DD1B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransformPrgView : public CView
{
protected: // create from serialization only
	CTransformPrgView();
	DECLARE_DYNCREATE(CTransformPrgView)

// Attributes
public:
	CTransformPrgDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransformPrgView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawObject(CDC *pDC);
	void BorderCheck();
	void ReadPoint();
	void DoubleBuffer();
	virtual ~CTransformPrgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CP2    *P;//变换点
	int	   directionX,directionY;//位移方向
	double translateX,translateY,rotate;
	double scale;
	int    degree;
	double R;//图形半径
	CTransForm tran;//变换对象


// Generated message map functions
protected:
	//{{AFX_MSG(CTransformPrgView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TransformPrgView.cpp
inline CTransformPrgDoc* CTransformPrgView::GetDocument()
   { return (CTransformPrgDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSFORMPRGVIEW_H__C2B1673D_D039_46B4_AC00_4AC0EF1DD1B8__INCLUDED_)
