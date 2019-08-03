// DesignView.h : interface of the CDesignView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DESIGNVIEW_H__B627425B_60FD_47CA_B7BE_91F86D732FEA__INCLUDED_)
#define AFX_DESIGNVIEW_H__B627425B_60FD_47CA_B7BE_91F86D732FEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDesignView : public CView
{
protected: // create from serialization only
	CDesignView();
	DECLARE_DYNCREATE(CDesignView)

// Attributes
public:
	CDesignDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDesignView)
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
	COLORREF pencolor;
	CPoint endPoint;
	CPoint startPoint;
	virtual ~CDesignView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDesignView)
	afx_msg void OnLine();
	afx_msg void OnUpdateLine(CCmdUI* pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnEllipse();
	afx_msg void OnRectangle();
	afx_msg void OnPencolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_startRect;
	CPoint m_startPoint;
	CPoint m_OldPoint;
	UINT m_drawType;
	HCURSOR m_HCross;
};

#ifndef _DEBUG  // debug version in DesignView.cpp
inline CDesignDoc* CDesignView::GetDocument()
   { return (CDesignDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DESIGNVIEW_H__B627425B_60FD_47CA_B7BE_91F86D732FEA__INCLUDED_)
