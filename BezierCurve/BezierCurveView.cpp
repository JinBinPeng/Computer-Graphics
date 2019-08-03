// BezierCurveView.cpp : implementation of the CBezierCurveView class
//

#include "stdafx.h"
#include "BezierCurve.h"

#include "BezierCurveDoc.h"
#include "BezierCurveView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveView

IMPLEMENT_DYNCREATE(CBezierCurveView, CView)

BEGIN_MESSAGE_MAP(CBezierCurveView, CView)
	//{{AFX_MSG_MAP(CBezierCurveView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_BEZIER, OnBezier)
	ON_COMMAND(ID_DECASTE, OnDecaste)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveView construction/destruction

CBezierCurveView::CBezierCurveView()
{
	// TODO: add construction code here
	P=new CPoint[N_MAX_POINT];//存放控制多边形顶点数组
	bFlag=TRUE;
	CtrlPointNum=0;
}

CBezierCurveView::~CBezierCurveView()
{
	if(P!=NULL)
	{
		delete []P;
		P=NULL;
	}

}

BOOL CBezierCurveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveView drawing

void CBezierCurveView::OnDraw(CDC* pDC)
{
	CBezierCurveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
        pDC->TextOut(0,0,"左键绘制控制多边形，通过菜单选择相应算法输出曲线");
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveView diagnostics

#ifdef _DEBUG
void CBezierCurveView::AssertValid() const
{
	CView::AssertValid();
}

void CBezierCurveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBezierCurveDoc* CBezierCurveView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBezierCurveDoc)));
	return (CBezierCurveDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CBezierCurveView message handlers

void CBezierCurveView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(bFlag)
	{
		P[CtrlPointNum].x=point.x;
		P[CtrlPointNum].y=point.y;
		if(CtrlPointNum<N_MAX_POINT-1)//N_MAX_POINT为控制点个数的最大值
			CtrlPointNum++;
		else
			bFlag=FALSE;
		n=CtrlPointNum-1;
		DrawCtrlPolygon();
	}

	
	CView::OnLButtonDown(nFlags, point);
}

void CBezierCurveView::DrawCtrlPolygon()
{
    CDC *pDC=GetDC();
	CBrush NewBrush,*pOldBrush;
	pOldBrush=(CBrush*)pDC->SelectStockObject(GRAY_BRUSH);//灰色实心圆绘制控制点
	for(int i=0;i<=n;i++)
	{
		if(0==i)
		{
			pDC->MoveTo(P[i]);
			pDC->Ellipse(P[i].x-2,P[i].y-2,P[i].x+2,P[i].y+2);
		}
		else
		{
			pDC->LineTo(P[i]);
			pDC->Ellipse(P[i].x-2,P[i].y-2,P[i].x+2,P[i].y+2);
		}
	}
	pDC->SelectObject(pOldBrush);
	ReleaseDC(pDC);
}

void CBezierCurveView::OnBezier() 
{
	// TODO: Add your command handler code here
	if(0!=CtrlPointNum)
		DrawnBezier();
	CtrlPointNum=0;

}

void CBezierCurveView::OnDecaste() 
{
	// TODO: Add your command handler code here
	if(0!=CtrlPointNum)
		DrawDeBezier();	
	CtrlPointNum=0;

}

void CBezierCurveView::DrawnBezier()
{
    CDC *pDC=GetDC();
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//曲线颜色为蓝色
	pOldPen=pDC->SelectObject(&NewPen);	
	pDC->MoveTo(P[0]);
	for(double t=0.0;t<=1.0;t+=0.01)
	{		
		double x=0,y=0;
		for(int i=0;i<=n;i++)
		{
			x+=P[i].x*Cni(n,i)*pow(t,i)*pow(1-t,n-i);
			y+=P[i].y*Cni(n,i)*pow(t,i)*pow(1-t,n-i);
		}
		pDC->LineTo(Round(x),Round(y));
	}
	pDC->SelectObject(pOldPen);
	NewPen.DeleteObject();
	ReleaseDC(pDC);
}

void CBezierCurveView::DrawDeBezier()
{
CDC *pDC=GetDC();
	CPen NewPen,*pOldPen;
	NewPen.CreatePen(PS_SOLID,1,RGB(0,0,255));//控制多边形
	pOldPen=pDC->SelectObject(&NewPen);
	CP2 *pt=new CP2[CtrlPointNum];
	pp=new CP2 *[CtrlPointNum];//设置行指针
	for(int i=0;i<CtrlPointNum;i++)
		pp[i]=new CP2[CtrlPointNum];//分配一个一维数组为一行
	pDC->MoveTo(P[0]);
	for(int k=0;k<=n;k++)
	{
		pt[k].x=P[k].x;
		pt[k].y=P[k].y;
	}
    for(double t=0.0;t<=1.0;t+=0.01)
	{
		deCasteljau(t,pt);
	    pDC->LineTo(Round(pp[0][n].x),Round(pp[0][n].y));	
	}
	NewPen.DeleteObject();
	ReleaseDC(pDC);
	if(pt!=NULL)
	{
		delete []pt;
		pt=NULL;
	}
	for(int j=0;j<CtrlPointNum;j++)
	{
		delete[] pp[j];
		pp[j]=NULL;
	}
	delete[] pp;
	pp=NULL;
}

void CBezierCurveView::deCasteljau(double t, CP2 *p)
{
	for(int k=0;k<=n;k++)
		pp[k][0]=p[k];
	for(int r=1;r<=n;r++)//de Casteljau递推公式
	{
		for(int i=0;i<=n-r;i++)
		{ 
			pp[i][r].x=(1-t)*pp[i][r-1].x+t*pp[i+1][r-1].x;
			pp[i][r].y=(1-t)*pp[i][r-1].y+t*pp[i+1][r-1].y;
		} 
    } 

}

long CBezierCurveView::Fac(int m)
{
	//自行编写Fac(int m)代码
	long z=1;
    while(m>0){
	z=m*z;
	m--;}
    return z;

}
double CBezierCurveView::Cni(const int &n, const int &i)
{
//自行编写Cni(const int &n, const int &i)代码
  return Fac(n)/(Fac(i)*Fac(n-i));
}
