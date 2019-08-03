// B3CurvesView.cpp : implementation of the CB3CurvesView class
//

#include "stdafx.h"
#include "B3Curves.h"

#include "B3CurvesDoc.h"
#include "B3CurvesView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView

IMPLEMENT_DYNCREATE(CB3CurvesView, CView)

BEGIN_MESSAGE_MAP(CB3CurvesView, CView)
	//{{AFX_MSG_MAP(CB3CurvesView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView construction/destruction

CB3CurvesView::CB3CurvesView()
{
	// TODO: add construction code here
	 m_AbleToLeftBtn=FALSE;
	m_AbleToMove=FALSE;
	m_i=-1;
	//初始化9个控制点
	P[0].x=120;P[0].y=350;
	P[1].x=250;P[1].y=250;
	P[2].x=316;P[2].y=420;
	P[3].x=428;P[3].y=167;
	P[4].x=525;P[4].y=500;
	P[5].x=650;P[5].y=250;
	P[6].x=682;P[6].y=40;
	P[7].x=850;P[7].y=450;
	P[8].x=950;P[8].y=350;


}

CB3CurvesView::~CB3CurvesView()
{
}

BOOL CB3CurvesView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView drawing

void CB3CurvesView::OnDraw(CDC* pDC)
{
	CB3CurvesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect rect;//定义客户区
	GetClientRect(&rect);//获得客户区的大小
	CDC MemDC;//内存DC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载图像的临时位图
	MemDC.CreateCompatibleDC(pDC);//建立与屏幕pDC兼容的MemDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=MemDC.SelectObject(&NewBitmap); //将兼容位图选入MemDC 
	MemDC.FillSolidRect(rect,pDC->GetBkColor());//按原来背景填充客户区，否则是黑色 
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,3,RGB(0,0,0));
	pOldPen=MemDC.SelectObject(&NewPen);	
	MemDC.MoveTo(P[0]);
	MemDC.Ellipse(P[0].x-2,P[0].y-2,P[0].x+2,P[0].y+2);//绘制控制多边形顶点
	for(int i=1;i<9;i++)
	{
		MemDC.LineTo(P[i]);
		MemDC.Ellipse(P[i].x-2,P[i].y-2,P[i].x+2,P[i].y+2);
	}
	if(m_i!=-1)
	{
		CString	str;
		str.Format("x=%d,y=%d",P[m_i].x,P[m_i].y);
		MemDC.TextOut(P[m_i].x+5,P[m_i].y+5,str);
	}
	B3Curves(P,&MemDC);
	pDC->BitBlt(0,0,rect.Width(),rect.Height(),&MemDC,0,0,SRCCOPY);//将内存位图拷贝到屏幕
	MemDC.SelectObject(pOldPen);
	NewPen.DeleteObject();	
	MemDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
	MemDC.DeleteDC();//删除MemDC	

}

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView printing

BOOL CB3CurvesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CB3CurvesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CB3CurvesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView diagnostics

#ifdef _DEBUG
void CB3CurvesView::AssertValid() const
{
	CView::AssertValid();
}

void CB3CurvesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CB3CurvesDoc* CB3CurvesView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CB3CurvesDoc)));
	return (CB3CurvesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CB3CurvesView message handlers

void CB3CurvesView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_AbleToLeftBtn==TRUE)
		m_AbleToMove=TRUE;

	CView::OnLButtonDown(nFlags, point);
}

void CB3CurvesView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(TRUE==m_AbleToMove)
		P[m_i]=point;
	m_i=-1;
	int i;
	for(i=0;i<9;i++)
	{
		if((point.x-P[i].x)*(point.x-P[i].x)+(point.y-P[i].y)*(point.y-P[i].y)<50)
		{
			m_i=i;
			m_AbleToLeftBtn=TRUE;
			SetCursor(LoadCursor(NULL,IDC_SIZEALL));//改变为十字箭头光标
			break;
		}
	}
	if(10==i)
	{
		m_i=-1;
	}
	Invalidate(FALSE);	

	CView::OnMouseMove(nFlags, point);
}

void CB3CurvesView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_AbleToLeftBtn=FALSE;
	m_AbleToMove=FALSE;
	m_i=0;

	CView::OnLButtonUp(nFlags, point);
}

void CB3CurvesView::B3Curves(CPoint q[], CDC *pDC)
{
    CPoint p;
	double F03,F13,F23,F33;
	p.x=Round((q[0].x+4.0*q[1].x+q[2].x)/6.0);//t＝0的起点x坐标
	p.y=Round((q[0].y+4.0*q[1].y+q[2].y)/6.0);//t＝0的起点y坐标
	pDC->MoveTo(p);
	CPen NewPen(PS_SOLID,1,RGB(255,0,0));//红笔画B样条曲线
	CPen *pOldPen=pDC->SelectObject(&NewPen);
	for(int i=1;i<7;i++)//6段样条曲线
	{
		for(double t=0;t<=1;t+=0.01)
		{
			F03=(-t*t*t+3*t*t-3*t+1)/6;//计算F0,3(t)
			F13=(3*t*t*t-6*t*t+4)/6;//计算F1,3(t)
			F23=(-3*t*t*t+3*t*t+3*t+1)/6;//计算F2,3(t)
			F33=t*t*t/6;//计算B3,3(t)
			p.x=Round(q[i-1].x*F03+q[i].x*F13+q[i+1].x*F23+q[i+2].x*F33);
			p.y=Round(q[i-1].y*F03+q[i].y*F13+q[i+1].y*F23+q[i+2].y*F33);
			pDC->LineTo(p);
		}
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();	
}

