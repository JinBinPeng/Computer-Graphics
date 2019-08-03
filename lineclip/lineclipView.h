// lineclipView.h : interface of the CLineclipView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINECLIPVIEW_H__5412EC3F_11AF_456D_8327_4ED3159C4324__INCLUDED_)
#define AFX_LINECLIPVIEW_H__5412EC3F_11AF_456D_8327_4ED3159C4324__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLineclipView : public CView
{
protected: // create from serialization only
	CLineclipView();
	DECLARE_DYNCREATE(CLineclipView)

// Attributes
public:
	CLineclipDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineclipView)
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
	void displayline(int x1, int  y1,int x2, int y2);
	BOOL ClipT( float p, float q, float *u1,float *u2);
	int encode(int x, int y);
	void liang();
	void cohen();
	CPoint endpoint;
	CPoint startpoint;
	CString clip;
	CString text;
	CString currentPos;
	CPoint m_current;
	int drawing;
	CPoint m_prev;
	int draw;
	CRect clipwin;
	int wxl;
	int wxr;
	int wyt;
	int wyb;
	virtual ~CLineclipView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineclipView)
	afx_msg void OnButton32772();
	afx_msg void OnUpdateButton1(CCmdUI* pCmdUI);
	afx_msg void OnButton1();
	afx_msg void OnUpdateButton32772(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBcohan();
	afx_msg void OnBliang();
	afx_msg void OnUpdatePos(CCmdUI * pCmUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in lineclipView.cpp
inline CLineclipDoc* CLineclipView::GetDocument()
   { return (CLineclipDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINECLIPVIEW_H__5412EC3F_11AF_456D_8327_4ED3159C4324__INCLUDED_)
