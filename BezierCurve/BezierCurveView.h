// BezierCurveView.h : interface of the CBezierCurveView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BEZIERCURVEVIEW_H__763D4DF2_23B7_4C7B_87F1_8006F7C362B7__INCLUDED_)
#define AFX_BEZIERCURVEVIEW_H__763D4DF2_23B7_4C7B_87F1_8006F7C362B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "p2.h"
#define N_MAX_POINT 21//���ƶ���ε���󶥵���
#include "math.h"//��ѧͷ�ļ�
#define Round(d) int(floor(d+0.5))//��������궨��


class CBezierCurveView : public CView
{
protected: // create from serialization only
	CBezierCurveView();
	DECLARE_DYNCREATE(CBezierCurveView)

	BOOL bFlag; //��־
	CPoint *P;//����
	int  CtrlPointNum;//���ƶ���ζ������
	int  n;//Bezier���ߵĽ״�	
    CP2  **pp;//��ά��̬����

// Attributes
public:
	CBezierCurveDoc* GetDocument();

	void DrawCtrlPolygon();//���ƿ��ƶ���κ���
	long  Fac(int m);//�׳˺���
	double Cni(const int &n,const int &i);//Bernstein������������� 
	void DrawnBezier ();//Bezier���߷��̻��ƺ���
    void DrawDeBezier();//�����㷨����Bezier����
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
