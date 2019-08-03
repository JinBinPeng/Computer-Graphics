// GraphicFillView.h : interface of the CGraphicFillView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRAPHICFILLVIEW_H__96185245_7F86_4809_9FA6_183C72CB077B__INCLUDED_)
#define AFX_GRAPHICFILLVIEW_H__96185245_7F86_4809_9FA6_183C72CB077B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGraphicFillView : public CView
{
protected: // create from serialization only
	CGraphicFillView();
	DECLARE_DYNCREATE(CGraphicFillView)

// Attributes
public:
	CGraphicFillDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphicFillView)
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
	void boundaryFill4_stack(int x, int y, COLORREF fill, COLORREF boundary);
	void ScanLineFill4(int x,int y,COLORREF oldcolor,COLORREF newcolor);
	void floodFill4(int x,int y,COLORREF oldcolor,COLORREF newcolor);
	int suanfa;
	void boundaryFill4(int x,int y,COLORREF fill,COLORREF boundary);
	int cpok;
	int isfill;
	CPoint currentpoint;
	CPoint a[5];
	CRect clipwin;
	COLORREF pencolor;
	COLORREF boundarycolor;
	virtual ~CGraphicFillView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGraphicFillView)
	afx_msg void OnPencolor();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBoundary();
	afx_msg void OnFloodfill();
	afx_msg void OnEdgefill();
	afx_msg void OnEdgemarkfill();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GraphicFillView.cpp
inline CGraphicFillDoc* CGraphicFillView::GetDocument()
   { return (CGraphicFillDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHICFILLVIEW_H__96185245_7F86_4809_9FA6_183C72CB077B__INCLUDED_)
