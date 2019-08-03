// BresenhamView.h : interface of the CBresenhamView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRESENHAMVIEW_H__ECA153F9_6BB2_4621_9380_0E12B3F8BE18__INCLUDED_)
#define AFX_BRESENHAMVIEW_H__ECA153F9_6BB2_4621_9380_0E12B3F8BE18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBresenhamView : public CView
{
protected: // create from serialization only
	CBresenhamView();
	DECLARE_DYNCREATE(CBresenhamView)

// Attributes
public:
	CBresenhamDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBresenhamView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBresenhamView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBresenhamView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BresenhamView.cpp
inline CBresenhamDoc* CBresenhamView::GetDocument()
   { return (CBresenhamDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRESENHAMVIEW_H__ECA153F9_6BB2_4621_9380_0E12B3F8BE18__INCLUDED_)
