// B3CurvesView.h : interface of the CB3CurvesView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_B3CURVESVIEW_H__D25EBFF9_E9A8_4B1C_9282_A21F1912629C__INCLUDED_)
#define AFX_B3CURVESVIEW_H__D25EBFF9_E9A8_4B1C_9282_A21F1912629C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "math.h"//��ѧͷ�ļ�
#define Round(d) int(floor(d+0.5))//��������궨��



class CB3CurvesView : public CView
{
protected: // create from serialization only
	CB3CurvesView();
	DECLARE_DYNCREATE(CB3CurvesView)

	BOOL	m_AbleToLeftBtn;//��������Ч
	BOOL	m_AbleToMove;//����ƶ�����Ч
	int		m_i;//���Ƶ�������
	CPoint	P[9];//����


// Attributes
public:
	CB3CurvesDoc* GetDocument();

	void B3Curves(CPoint q[],CDC *pDC);//����B��������

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CB3CurvesView)
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
	virtual ~CB3CurvesView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CB3CurvesView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in B3CurvesView.cpp
inline CB3CurvesDoc* CB3CurvesView::GetDocument()
   { return (CB3CurvesDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_B3CURVESVIEW_H__D25EBFF9_E9A8_4B1C_9282_A21F1912629C__INCLUDED_)
