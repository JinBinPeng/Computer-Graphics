// TransformPrgView.cpp : implementation of the CTransformPrgView class
//

#include "stdafx.h"
#include "TransformPrg.h"

#include "TransformPrgDoc.h"
#include "TransformPrgView.h"

#include "Line.h"//直线类
#include "Mainfrm.h"//主框架头文件
#define ROUND(a) int(a+0.5)//四舍五入
#include "math.h"//数学头文件
#define  PI 3.14159265//圆周率


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView

IMPLEMENT_DYNCREATE(CTransformPrgView, CView)

BEGIN_MESSAGE_MAP(CTransformPrgView, CView)
	//{{AFX_MSG_MAP(CTransformPrgView)
	ON_WM_TIMER()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView construction/destruction

CTransformPrgView::CTransformPrgView()
{
	// TODO: add construction code here
	degree=0;
	translateX=0;
	translateY=0;
	rotate=0;
	directionX=1;
	directionY=1;
	scale=0;	
	R=100;
}

CTransformPrgView::~CTransformPrgView()
{
}

BOOL CTransformPrgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView drawing

void CTransformPrgView::OnDraw(CDC* pDC)
{
	CTransformPrgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	SetTimer(1,50,NULL);//设置定时器
}

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView printing

BOOL CTransformPrgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTransformPrgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTransformPrgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView diagnostics

#ifdef _DEBUG
void CTransformPrgView::AssertValid() const
{
	CView::AssertValid();
}

void CTransformPrgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTransformPrgDoc* CTransformPrgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTransformPrgDoc)));
	return (CTransformPrgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransformPrgView message handlers

void CTransformPrgView::DoubleBuffer()
{
    CDC* pDC=GetDC();
	CRect rect;//定义客户区
	GetClientRect(&rect);//获得客户区的大小
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC自定义坐标系
	pDC->SetWindowExt(rect.Width(),rect.Height());//设置窗口范围
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x轴水平向右，y轴垂直向上
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//屏幕中心为原点
	CDC MemDC;//内存DC
	CBitmap NewBitmap,*pOldBitmap;//内存中承载图像的临时位图
	MemDC.CreateCompatibleDC(pDC);//建立与屏幕pDC兼容的MemDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//创建兼容位图 
	pOldBitmap=MemDC.SelectObject(&NewBitmap); //将兼容位图选入MemDC 
	MemDC.SetMapMode(MM_ANISOTROPIC);//MemDC自定义坐标系
	MemDC.SetWindowExt(rect.Width(),rect.Height());
	MemDC.SetViewportExt(rect.Width(),-rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	ReadPoint();//计算图形顶点坐标
	tran.Translate(translateX,translateY);//平移变换
	tran.Rotate(rotate,CP2(translateX,translateY));//相对于任意点的旋转变换
	tran.Scale(scale,scale,CP2(translateX,translateY));//相对于任意点的比例变换
	DrawObject(&MemDC);
	BorderCheck();	
	pDC->BitBlt(-rect.Width()/2,-rect.Height()/2,rect.Width(),rect.Height(),&MemDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//将内存位图拷贝到屏幕
	MemDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
	MemDC.DeleteDC();//删除MemDC
	ReleaseDC(pDC);//释放DC
	if (P!=NULL)
	{
		delete []P;
		P=NULL;
	}

}

void CTransformPrgView::ReadPoint()
{
    double Dtheta=2*PI/degree;
	P=new CP2[degree+1];
	for(int i=0;i<degree;i++)
	{
		P[i].x=R*cos(i*Dtheta);
		P[i].y=R*sin(i*Dtheta);
	}
	P[degree].x=0;P[degree].y=0;//图形中心点
	tran.SetMat(P,degree+1);
}


void CTransformPrgView::BorderCheck()
{
	double TempR=R*scale;
	CRect rect;//定义客户区
	GetClientRect(&rect);//获得客户区的大小
	int nWidth=rect.Width()/2;
	int nHeight=rect.Height()/2;
	if(fabs(P[degree].x)+TempR>nWidth)
	{
		directionX*=-1;
		translateX+=fabs(fabs(P[degree].x)+TempR-nWidth)*directionX;//判断球体水平越界
	}
	if(fabs(P[degree].y)+TempR>nHeight)
	{
		directionY*=-1;
		translateY+=fabs(fabs(P[degree].y)+TempR-nHeight)*directionY;//判断球体垂直越界
	}

}

void CTransformPrgView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTransformPrgDoc* pDoc=GetDocument();
	if(((CMainFrame*)AfxGetMainWnd())->IsPlay)
	{
		degree=pDoc->m_degree;
		translateX+=pDoc->m_translateX*directionX;
		translateY+=pDoc->m_translateY*directionY;
		rotate+=pDoc->m_rotate;	
		scale=pDoc->m_scale;		
		DoubleBuffer();
	}

	CView::OnTimer(nIDEvent);
}

BOOL CTransformPrgView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}

void CTransformPrgView::DrawObject(CDC *pDC)
{
	CLine *line=new CLine;
	for(int i=0;i<degree;i++)
	{
		line->MoveTo(pDC,ROUND(P[degree].x),ROUND(P[degree].y));
        line->LineTo(pDC,ROUND(P[i].x),ROUND(P[i].y));
		line->LineTo(pDC,ROUND(P[(i+1)%degree].x),ROUND(P[(i+1)%degree].y));
	}
	delete line;
}
