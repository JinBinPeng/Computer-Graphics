// polygonView.h : interface of the CPolygonView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POLYGONVIEW_H__A449320A_BFB8_4057_BD70_A11A1FE73C4B__INCLUDED_)
#define AFX_POLYGONVIEW_H__A449320A_BFB8_4057_BD70_A11A1FE73C4B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPolygonView : public CView
{
protected: // create from serialization only
	CPolygonView();
	DECLARE_DYNCREATE(CPolygonView)

// Attributes
public:
	CPolygonDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPolygonView)
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
	void Intersect(CPoint S,CPoint P,CPoint ClipBoundary[2],CPoint &IntersectPt);
	bool Inside(CPoint TestPt, CPoint ClipBoundary[]);
	void SutherlandHodgmanClip(CPoint InVertexArray[],CPoint OutVertexArray[],CPoint ClipBoundary[2],int Inlength,int &Outlength);
	void Output(CPoint P,int Outlength,CPoint OutVertexArray[]);
	int outlen;
    int inlen;

	CPointList list;
	int cliptype;
	CPoint a[100];
	CPoint b[100];	
    CPoint clipedge[2];
	CRect clipwin;
	virtual ~CPolygonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPolygonView)
	afx_msg void OnSh();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in polygonView.cpp
inline CPolygonDoc* CPolygonView::GetDocument()
   { return (CPolygonDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONVIEW_H__A449320A_BFB8_4057_BD70_A11A1FE73C4B__INCLUDED_)
