// transform_newView.cpp : implementation of the CTransform_newView class
//

#include "stdafx.h"
#include "transform_new.h"

#include "transform_newDoc.h"
#include "transform_newView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTransform_newView

IMPLEMENT_DYNCREATE(CTransform_newView, CView)

BEGIN_MESSAGE_MAP(CTransform_newView, CView)
	//{{AFX_MSG_MAP(CTransform_newView)
	ON_COMMAND(IDB_LEFT, OnLeft)
	ON_COMMAND(IDB_REFRESH, OnRefresh)
	ON_COMMAND(IDB_RIGHT, OnRight)
	ON_COMMAND(IDB_DOWN, OnDown)
	ON_COMMAND(IDB_REFLECTORG, OnReflectorg)
	ON_COMMAND(IDB_REFLECTX, OnReflectx)
	ON_COMMAND(IDB_REFLECTY, OnReflecty)
	ON_COMMAND(IDB_ROTATELEFT, OnRotateleft)
	ON_COMMAND(IDB_ROTATERIGHT, OnRotateright)
	ON_COMMAND(IDB_SCALEDOWN, OnScaledown)
	ON_COMMAND(IDB_SCALEUP, OnScaleup)
	ON_COMMAND(IDB_SHEARDOWN, OnSheardown)
	ON_COMMAND(IDB_SHEARLEFT, OnShearleft)
	ON_COMMAND(IDB_SHEARRIGHT, OnShearright)
	ON_COMMAND(IDB_SHEARUP, OnShearup)
	ON_COMMAND(IDB_UP, OnUp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTransform_newView construction/destruction

CTransform_newView::CTransform_newView()
{
	// TODO: add construction code here
 initRect();

}

CTransform_newView::~CTransform_newView()
{
}

BOOL CTransform_newView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTransform_newView drawing

void CTransform_newView::OnDraw(CDC* pDC)
{
	CTransform_newDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
   DoubleBuffer();
    

}

/////////////////////////////////////////////////////////////////////////////
// CTransform_newView diagnostics

#ifdef _DEBUG
void CTransform_newView::AssertValid() const
{
	CView::AssertValid();
}

void CTransform_newView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTransform_newDoc* CTransform_newView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTransform_newDoc)));
	return (CTransform_newDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTransform_newView message handlers

void CTransform_newView::OnLeft() 
{
	// TODO: Add your command handler code here
	transform.Translate(-10,0);
    Invalidate(TRUE);
}

void CTransform_newView::initRect()
{
   points[0].x=50;
   points[0].y=50;  
   points[1].x=250;
   points[1].y=50;
   points[2].x=250;
   points[2].y=200;
   points[3].x=50;
   points[3].y=200;
   transform.SetMat(points,4);

}

void CTransform_newView::drawPoly(CDC *pDC)
{
  	CP2 t;
	for(int i=0;i<4;i++)//绘制多边形
	{
		if(i==0)
		{
			pDC->MoveTo(points[i].x,points[i].y);
			t=points[i];
		}
		else
		{
			pDC->LineTo(points[i].x,points[i].y);
		}		
	}
	pDC->LineTo(t.x,t.y);//闭合多边形
}

void CTransform_newView::OnRefresh() 
{
	// TODO: Add your command handler code here
	 initRect();
	 Invalidate(TRUE);
}

void CTransform_newView::DoubleBuffer()
{
    CDC* pDC=GetDC();
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
	MemDC.FillSolidRect(&rect,pDC->GetBkColor());//按原来背景填充客户区，否则是黑色
	MemDC.SetMapMode(MM_ANISOTROPIC);//MemDC自定义坐标系
	MemDC.SetWindowExt(rect.Width(),rect.Height());
	MemDC.SetViewportExt(rect.Width(),-rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
    rect.OffsetRect(-rect.Width()/2,-rect.Height()/2);//客户区矩形校正

	DrawObject(&MemDC);

	pDC->BitBlt(-rect.Width()/2,-rect.Height()/2,rect.Width(),rect.Height(),&MemDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//将内存位图拷贝到屏幕
	MemDC.SelectObject(pOldBitmap);//恢复位图
	NewBitmap.DeleteObject();//删除位图
	ReleaseDC(pDC);//释放DC	
}

void CTransform_newView::DrawObject(CDC *pDC)
{
	pDC->MoveTo(rect.left,0);//绘制x轴
	pDC->LineTo(rect.right,0);	
	pDC->MoveTo(rect.right-10,5);//绘制右箭头　
	pDC->LineTo(rect.right,0);
	pDC->LineTo(rect.right-10,-5);
	pDC->LineTo(rect.right,0);
	pDC->TextOut(rect.right-20,30,"x");
	pDC->MoveTo(0,rect.top);//绘制y轴
	pDC->LineTo(0,rect.bottom);
	pDC->MoveTo(-5,rect.bottom-10);//绘制上箭头
	pDC->LineTo(0,rect.bottom);
	pDC->LineTo(5,rect.bottom-10);
	pDC->LineTo(0,rect.bottom);
	pDC->TextOut(-30,rect.bottom-20,"y");
	pDC->TextOut(-20,-10,"O");
	drawPoly(pDC);
}

void CTransform_newView::OnRight() 
{
	// TODO: Add your command handler code here
	transform.Translate(10,0);
    Invalidate(TRUE);
}

void CTransform_newView::OnUp() 
{
	// TODO: Add your command handler code here
	transform.Translate(0,10);
    Invalidate(TRUE);
	
}
void CTransform_newView::OnDown() 
{
	// TODO: Add your command handler code here
	transform.Translate(0,-10);
    Invalidate(TRUE);
}

void CTransform_newView::OnReflectorg() 
{
	// TODO: Add your command handler code here
	transform.ReflectOrg();
    Invalidate(TRUE);
}

void CTransform_newView::OnReflectx() 
{
	// TODO: Add your command handler code here
    transform.ReflectX();
    Invalidate(TRUE);
	
}

void CTransform_newView::OnReflecty() 
{
	// TODO: Add your command handler code here
	transform.ReflectY();
    Invalidate(TRUE);
}

void CTransform_newView::OnRotateleft() 
{
	// TODO: Add your command handler code here
	CP2 t;
	t.x=(points[0].x+points[2].x)/2;
    t.y=(points[0].y+points[2].y)/2;
	transform.Rotate(30,t);
    Invalidate(TRUE);
}

void CTransform_newView::OnRotateright() 
{
	// TODO: Add your command handler code here
	CP2 t;
	t.x=(points[0].x+points[2].x)/2;
    t.y=(points[0].y+points[2].y)/2;
	transform.Rotate(-30,t);
    Invalidate(TRUE);
	
}

void CTransform_newView::OnScaledown() 
{
	// TODO: Add your command handler code here
	CP2 t;
	t.x=(points[0].x+points[2].x)/2;
    t.y=(points[0].y+points[2].y)/2;
	transform.Scale(0.5,0.5,t);
    Invalidate(TRUE);
}

void CTransform_newView::OnScaleup() 
{
	// TODO: Add your command handler code here
	CP2 t;
	t.x=(points[0].x+points[2].x)/2;
    t.y=(points[0].y+points[2].y)/2;
	transform.Scale(2,2,t);
    Invalidate(TRUE);
	
}

void CTransform_newView::OnSheardown() 
{
	// TODO: Add your command handler code here
	transform.Shear(-1,0);
	Invalidate(TRUE);
}

void CTransform_newView::OnShearleft() 
{
	// TODO: Add your command handler code here
	transform.Shear(0,1);
	Invalidate(TRUE);
}

void CTransform_newView::OnShearright() 
{
	// TODO: Add your command handler code here
	transform.Shear(0,-1);
	Invalidate(TRUE);
}

void CTransform_newView::OnShearup() 
{
	// TODO: Add your command handler code here
	transform.Shear(1,0);
	Invalidate(TRUE);
}


