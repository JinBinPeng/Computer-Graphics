// BresenhamView.cpp : implementation of the CBresenhamView class
//

#include "stdafx.h"
#include "Bresenham.h"

#include "BresenhamDoc.h"
#include "BresenhamView.h"

#include "line.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBresenhamView

IMPLEMENT_DYNCREATE(CBresenhamView, CView)

BEGIN_MESSAGE_MAP(CBresenhamView, CView)
	//{{AFX_MSG_MAP(CBresenhamView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBresenhamView construction/destruction

CBresenhamView::CBresenhamView()
{
	// TODO: add construction code here

}

CBresenhamView::~CBresenhamView()
{
}

BOOL CBresenhamView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBresenhamView drawing

void CBresenhamView::OnDraw(CDC* pDC)
{
	CBresenhamDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// 以下设置坐标原点在屏幕中心，y轴正向朝上
	CRect rect;
	GetClientRect(&rect);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(rect.Width(),rect.Height());
	pDC->SetViewportExt(rect.Width(),-rect.Height());
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);
	rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);

	// 利用定义好的CLine类绘制线段
	CLine a;
	//水平的线段
	a.MoveTo(pDC,100,0);
	a.LineTo(pDC,-100,0);

	//垂直的线段
	a.MoveTo(pDC,0,-100);
	a.LineTo(pDC,0,100);

	//0<=k<=1的线段
	a.MoveTo(pDC,-100,-50);
	a.LineTo(pDC,100,50);

    //k=1
	a.MoveTo(pDC,-100,-100);
	a.LineTo(pDC,100,100);

	//k>1的线段
	a.MoveTo(pDC,-50,-100);
	a.LineTo(pDC,50,100);
  
	//k<-1的线段
	a.MoveTo(pDC,-50,100);
	a.LineTo(pDC,50,-100);

	//-1<=k<0的线段
	a.MoveTo(pDC,100,-50);
	a.LineTo(pDC,-100,50);
	
	//k=-1的线段
	a.MoveTo(pDC,-100,100);
	a.LineTo(pDC,100,-100);
}

/////////////////////////////////////////////////////////////////////////////
// CBresenhamView diagnostics

#ifdef _DEBUG
void CBresenhamView::AssertValid() const
{
	CView::AssertValid();
}

void CBresenhamView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBresenhamDoc* CBresenhamView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBresenhamDoc)));
	return (CBresenhamDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBresenhamView message handlers
