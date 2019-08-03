// KochView.h : interface of the CKochView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KOCHVIEW_H__25CB14A2_7762_48B2_A8EA_EA8A70F9004F__INCLUDED_)
#define AFX_KOCHVIEW_H__25CB14A2_7762_48B2_A8EA_EA8A70F9004F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "InputDlg.h"//�Ի���
#include "P2.h"



class CKochView : public CView
{
protected: // create from serialization only
	CKochView();
	DECLARE_DYNCREATE(CKochView)

	CDC *pDC;//�豸�����Ķ���
	int n;//�ݹ����
	CP2 P0,P1;//ֱ�ߵ������յ�
	double Theta;//koch�н�	
	double L0,Alpha,d;//��ʼ�߶εĳ��Ⱥ���ʼ�Ƕ�,�ȷ��߶εĳ���


// Attributes
public:
	CKochDoc* GetDocument();
	void Koch(int n);//koch����

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKochView)
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
	virtual ~CKochView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKochView)
	afx_msg void OnKoch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KochView.cpp
inline CKochDoc* CKochView::GetDocument()
   { return (CKochDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KOCHVIEW_H__25CB14A2_7762_48B2_A8EA_EA8A70F9004F__INCLUDED_)
