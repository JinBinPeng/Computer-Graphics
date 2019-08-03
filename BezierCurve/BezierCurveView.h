// BezierCurveView.h : interface of the CBezierCurveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERCURVEVIEW_H__763D4DF2_23B7_4C7B_87F1_8006F7C362B7__INCLUDED_)
#define AFX_BEZIERCURVEVIEW_H__763D4DF2_23B7_4C7B_87F1_8006F7C362B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "p2.h"
#define N_MAX_POINT 21//控制多边形的最大顶点数
#include "math.h"//数学头文件
#define Round(d) int(floor(d+0.5))//四舍五入宏定义


class CBezierCurveView : public CView
{
protected: // create from serialization only
	CBezierCurveView();
	DECLARE_DYNCREATE(CBezierCurveView)

	BOOL bFlag; //标志
	CPoint *P;//顶点
	int  CtrlPointNum;//控制多边形顶点个数
	int  n;//Bezier曲线的阶次	
    CP2  **pp;//二维动态数组

// Attributes
public:
	CBezierCurveDoc* GetDocument();

	void DrawCtrlPolygon();//绘制控制多边形函数
	long  Fac(int m);//阶乘函数
	double Cni(const int &n,const int &i);//Bernstein基函数的组合项 
	void DrawnBezier ();//Bezier曲线方程绘制函数
    void DrawDeBezier();//递推算法绘制Bezier函数
	void deCasteljau(double t,CP2 *p);

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBezierCurveView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBezierCurveView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBezierCurveView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBezier();
	afx_msg void OnDecaste();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BezierCurveView.cpp
inline CBezierCurveDoc* CBezierCurveView::GetDocument()
   { return (CBezierCurveDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BEZIERCURVEVIEW_H__763D4DF2_23B7_4C7B_87F1_8006F7C362B7__INCLUDED_)
