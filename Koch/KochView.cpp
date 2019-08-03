// KochView.cpp : implementation of the CKochView class
//

#include "stdafx.h"
#include "Koch.h"

#include "KochDoc.h"
#include "KochView.h"

#define PI 3.1415926//PI的宏定义
#include "math.h"//数学头文件
#define Round(d) int(floor(d+0.5))//四舍五入宏定义


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKochView

IMPLEMENT_DYNCREATE(CKochView, CView)

BEGIN_MESSAGE_MAP(CKochView, CView)
	//{{AFX_MSG_MAP(CKochView)
	ON_COMMAND(ID_KOCH, OnKoch)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKochView construction/destruction

CKochView::CKochView()
{
	// TODO: add construction code here
	pDC=NULL;  

}

CKochView::~CKochView()
{
}

BOOL CKochView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKochView drawing

void CKochView::OnDraw(CDC* pDC)
{
	CKochDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKochView printing

BOOL CKochView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKochView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKochView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKochView diagnostics

#ifdef _DEBUG
void CKochView::AssertValid() const
{
	CView::AssertValid();
}

void CKochView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKochDoc* CKochView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKochDoc)));
	return (CKochDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKochView message handlers

void CKochView::OnKoch() 
{
	// TODO: Add your command handler code here
	CInputDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		n=dlg.m_n;
	    Theta=dlg.m_a;
	}
	else
 		return;
 	RedrawWindow();	
	pDC=GetDC();
	CRect rect;//客户区矩形对象
	GetClientRect(&rect);	
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);
	P0.x=-rect.Width()/2.0,P0.y=-rect.Height()/2.0+100;
	P1.x=rect.Width()/2.0,P1.y=-rect.Height()/2.0+100;
	Alpha=atan((P1.y-P0.y)/(P1.x-P0.x));
	L0=sqrt((P1.x-P0.x)*(P1.x-P0.x)+(P1.y-P0.y)*(P1.y-P0.y));
	Theta=Theta*PI/180;
	d=L0/pow(2*(1+cos(Theta)),n);
	Koch(n);
	ReleaseDC(pDC);

}
void CKochView::Koch(int n)
{
   if(0==n)
    {
		P1.x=P0.x+d*cos(Alpha);
		P1.y=P0.y+d*sin(Alpha);
		pDC->MoveTo(Round(P0.x),Round(P0.y));
		pDC->LineTo(Round(P1.x),Round(P1.y));
		P0=P1;
		return;
    }
	Koch(n-1);
    Alpha+=Theta;
    Koch(n-1);
    Alpha-=2*Theta;
    Koch(n-1);
    Alpha+=Theta;
    Koch(n-1);
}
