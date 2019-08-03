// LeftPortion.cpp : implementation file
//

#include "stdafx.h"
#include "TransformPrg.h"
#include "LeftPortion.h"
#include "math.h"
#include "TransformPrgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLeftPortion

IMPLEMENT_DYNCREATE(CLeftPortion, CFormView)

CLeftPortion::CLeftPortion()
	: CFormView(CLeftPortion::IDD)
{
	//{{AFX_DATA_INIT(CLeftPortion)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CLeftPortion::~CLeftPortion()
{
}

void CLeftPortion::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLeftPortion)
	DDX_Control(pDX, IDC_SLIDER5, m_scale);
	DDX_Control(pDX, IDC_SLIDER4, m_rotate);
	DDX_Control(pDX, IDC_SLIDER3, m_translateY);
	DDX_Control(pDX, IDC_SLIDER2, m_translateX);
	DDX_Control(pDX, IDC_SLIDER1, m_degree);
	DDX_Control(pDX, IDC_CURFACE, m_curface);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLeftPortion, CFormView)
	//{{AFX_MSG_MAP(CLeftPortion)
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLeftPortion diagnostics

#ifdef _DEBUG
void CLeftPortion::AssertValid() const
{
	CFormView::AssertValid();
}

void CLeftPortion::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLeftPortion message handlers

void CLeftPortion::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	m_degree.SetRange(1,4,TRUE);
	m_degree.SetPos(2);
	m_translateX.SetRange(0,10,TRUE);
	m_translateX.SetPos(6);
	m_translateX.SetTicFreq(2);
	m_translateX.SetPageSize(2);
	m_translateY.SetRange(0,10,TRUE);
	m_translateY.SetPos(2);
	m_translateY.SetTicFreq(2);
	m_translateY.SetPageSize(2);
	m_rotate.SetRange(-10,10,TRUE);
	m_rotate.SetPos(5);
	m_rotate.SetTicFreq(5);
	m_rotate.SetPageSize(5);
	m_scale.SetRange(-2,2,TRUE);
	m_scale.SetPos(0);
	CString str("");
 	str.Format("三角形面片数：%d",(int(pow(2,m_degree.GetPos()+1))));
 	m_curface.SetWindowText(str);
	UpdateData(FALSE);

}

void CLeftPortion::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	
	CTransformPrgDoc *pDoc=(CTransformPrgDoc*)CFormView::GetDocument();
 	UpdateData();
 	switch(m_degree.GetPos())
 	{
 	case 1:
 		pDoc->m_degree=4;
 		break;
 	case 2:
 		pDoc->m_degree=8;
 		break;
 	case 3:
 		pDoc->m_degree=16;
 		break;
 	case 4:
 		pDoc->m_degree=32;
 		break;
 	}
	pDoc->m_translateX=m_translateX.GetPos();
 	pDoc->m_translateY=m_translateY.GetPos();
 	pDoc->m_rotate=m_rotate.GetPos(); 	
	switch(m_scale.GetPos())
 	{
 	case 2:
 		pDoc->m_scale=3.0;
 		break;
 	case 1:
 		pDoc->m_scale=2.0;
 		break;
 	case 0:
 		pDoc->m_scale=1.0;
 		break;
 	case -1:
 		pDoc->m_scale=0.5;
 		break;
 	case -2:
 		pDoc->m_scale=0.3;
 		break;
 	} 	
 	CString str("");
 	str.Format("三角形面片数：%d",(int(pow(2,m_degree.GetPos()+1))));
 	m_curface.SetWindowText(str);
 	UpdateData(FALSE);

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}
