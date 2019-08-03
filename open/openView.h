// openView.h : interface of the COpenView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENVIEW_H__0638FB36_7C94_4A1C_871A_043F0EA1CB71__INCLUDED_)
#define AFX_OPENVIEW_H__0638FB36_7C94_4A1C_871A_043F0EA1CB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class COpenView : public CView
{
protected: // create from serialization only
	COpenView();
	DECLARE_DYNCREATE(COpenView)

// Attributes
public:
	COpenDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenView)
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
	void axis(double length);
	void displayWire();
	void rotatecube(float angle,float rx,float ry,float rz);
	void scalecube(float sx,float sy,float sz);
	void movecube(float tx,float ty,float tz);
	int type;
	float tx,ty,tz;
	float sx,sy,sz;
	float angle,rx,ry,rz;
	void displaySolid(void);
	GLdouble aspect;
	BOOL CreateViewGLContext(HDC hDC);
	virtual ~COpenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
		HGLRC m_hGLContext;
	int m_GLPixelIndex;
	BOOL SetWindowPixelFormat(HDC hDC);
	//{{AFX_MSG(COpenView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTransform();
	afx_msg void OnScale();
	afx_msg void OnRo();
	afx_msg void OnFuhe();
	afx_msg void OnFanli();
	afx_msg void OnFanli1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in openView.cpp
inline COpenDoc* COpenView::GetDocument()
   { return (COpenDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENVIEW_H__0638FB36_7C94_4A1C_871A_043F0EA1CB71__INCLUDED_)
