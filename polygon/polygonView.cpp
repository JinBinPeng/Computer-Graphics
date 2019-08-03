// polygonView.cpp : implementation of the CPolygonView class
//

#include "stdafx.h"
#include "polygon.h"

#include "polygonDoc.h"
#include "polygonView.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPolygonView



IMPLEMENT_DYNCREATE(CPolygonView, CView)

BEGIN_MESSAGE_MAP(CPolygonView, CView)
	//{{AFX_MSG_MAP(CPolygonView)
	ON_COMMAND(ID_SH, OnSh)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPolygonView construction/destruction

CPolygonView::CPolygonView()
{
	// TODO: add construction code here
	cliptype=0;

}

CPolygonView::~CPolygonView()
{
}

BOOL CPolygonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonView drawing

void CPolygonView::OnDraw(CDC* pDC)
{
	CPolygonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect urect;
    GetClientRect(&urect);//获取客户区大小
    CPoint c=urect.CenterPoint();//获取矩形区中心坐标
    clipwin=CRect(c.x-150,c.y-100,c.x+150,c.y+100);//记录裁剪窗口坐标
    pDC->Rectangle(&clipwin);//绘制裁剪窗口 
	a[0].x=clipwin.left-50;
	a[0].y=clipwin.top-100;
	a[1].x=clipwin.right-50;
	a[1].y=clipwin.top-100;
	a[2].x=clipwin.right-100;
	a[2].y=clipwin.bottom+100;
	a[3].x=clipwin.right-150;
	a[3].y=clipwin.top-50;
	a[4].x=clipwin.left+100;
	a[4].y=clipwin.top+50;
	pDC->Polygon(a,5);
	CString currentPos;
	currentPos.Format("A:%d,%d",a[0].x,a[0].y);
    pDC->TextOut(10,10,currentPos);
	currentPos.Format("B:%d,%d",a[1].x,a[1].y);
    pDC->TextOut(10,40,currentPos);
	currentPos.Format("C:%d,%d",a[2].x,a[2].y);
    pDC->TextOut(10,70,currentPos);
	currentPos.Format("D:%d,%d",a[3].x,a[3].y);
    pDC->TextOut(10,100,currentPos);
	currentPos.Format("E:%d,%d",a[4].x,a[4].y);
    pDC->TextOut(10,130,currentPos);
	currentPos.Format("clipwin.左边界:%d",clipwin.left);
    pDC->TextOut(10,160,currentPos);
	currentPos.Format("clipwin.右边界:%d",clipwin.right);
    pDC->TextOut(10,190,currentPos);
	currentPos.Format("clipwin.上边界:%d",clipwin.top);
	pDC->TextOut(10,220,currentPos);	
	currentPos.Format("clipwin.下边界:%d",clipwin.bottom);
	pDC->TextOut(10,250,currentPos);
    
	pDC->TextOut(a[0].x-10,a[0].y,"A");
	pDC->TextOut(a[1].x+10,a[1].y,"B");
	pDC->TextOut(a[2].x+10,a[2].y,"C");
	pDC->TextOut(a[3].x,a[3].y-15,"D");
	pDC->TextOut(a[4].x-10,a[4].y,"E");

    

	if (cliptype==1)
	{
	  //请在此处调用sh裁剪算法
      //左边界  
	  clipedge[0]=CPoint(clipwin.left,clipwin.top);
	  clipedge[1]=CPoint(clipwin.left,clipwin.bottom);
	  inlen=5;
	  outlen=0;
      SutherlandHodgmanClip(a,b,clipedge,inlen,outlen);//左边界裁剪

	  //右边界  
	  clipedge[0]=CPoint(clipwin.right,clipwin.bottom);
	  clipedge[1]=CPoint(clipwin.right,clipwin.top);
	  inlen=outlen;
	  outlen=0;
      SutherlandHodgmanClip(b,a,clipedge,inlen,outlen);//右边界裁剪

      //上边界
	  clipedge[0]=CPoint(clipwin.top,clipwin.left);
	  clipedge[1]=CPoint(clipwin.top,clipwin.right);
	  inlen=outlen;
	  outlen=0;
      SutherlandHodgmanClip(a,b,clipedge,inlen,outlen);//上边界裁剪

	  //下边界
	  clipedge[0]=CPoint(clipwin.bottom,clipwin.right);
	  clipedge[1]=CPoint(clipwin.bottom,clipwin.left);
	  inlen=outlen;
	  outlen=0;
      SutherlandHodgmanClip(b,a,clipedge,inlen,outlen);//下边界裁剪

	  //以下是绘制多边形的代码
	  CPen *oldpen,newpen(PS_SOLID,1,RGB(245,34,23));
      oldpen=pDC->SelectObject(&newpen);
      pDC->Polygon(b,outlen);//b为CPoint类数组，存放多边形顶点
	  pDC->SelectObject(oldpen);
      newpen.DeleteObject();

	}

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonView printing

BOOL CPolygonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPolygonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPolygonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPolygonView diagnostics

#ifdef _DEBUG
void CPolygonView::AssertValid() const
{
	CView::AssertValid();
}

void CPolygonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPolygonDoc* CPolygonView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPolygonDoc)));
	return (CPolygonDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPolygonView message handlers

void CPolygonView::OnSh() 
{
	// TODO: Add your command handler code here
	cliptype=1;
    Invalidate();//察看ondraw函数看具体裁剪过程
}


void CPolygonView::SutherlandHodgmanClip(CPoint InVertexArray[], CPoint OutVertexArray[], CPoint ClipBoundary[], int Inlength, int &Outlength)
{
	CPoint S,P,ip;
	int j;
	Outlength=0;
	S=InVertexArray[Inlength-1];
	for(j=0;j<Inlength;j++)
	{
		P=InVertexArray[j];
		if(Inside(P,ClipBoundary))
		{
			if(Inside(S,ClipBoundary))
				Output(P,Outlength,OutVertexArray);
				else{
				Intersect(S,P,ClipBoundary,ip);
				Output(ip,Outlength,OutVertexArray);
				Output(P,Outlength,OutVertexArray);
			}
		}
		else if(Inside(S,ClipBoundary))
		{
			Intersect(S,P,ClipBoundary,ip);
			Output(ip,Outlength,OutVertexArray);
		}
		S=P;
	}
}

bool CPolygonView::Inside(CPoint TestPt, CPoint ClipBoundary[])
{
	if(ClipBoundary[1].x>ClipBoundary[0].x)  //裁剪边为窗口下边
	{
		if(TestPt.y>=ClipBoundary[0].x)
			return TRUE;
	}
	else if(ClipBoundary[1].x<ClipBoundary[0].x)  //裁剪边为窗口上边
	{
		if(TestPt.y<=ClipBoundary[0].y)
			return TRUE;
	}
		else if(ClipBoundary[1].y>ClipBoundary[0].y)  //裁剪边为窗口右边
	{
		if(TestPt.x<=ClipBoundary[0].x)
			return TRUE;
	}
		else if(ClipBoundary[1].y<ClipBoundary[0].y)  //裁剪边为窗口左边
	{
		if(TestPt.x>=ClipBoundary[0].x)
			return TRUE;
		}
		return FALSE;
}

void CPolygonView::Intersect(CPoint S, CPoint P, CPoint ClipBoundary[], CPoint &IntersectPt)
{
	if(ClipBoundary[0].y==ClipBoundary[1].y)
	{
		IntersectPt.y=ClipBoundary[0].y;
		IntersectPt.x=S.x+(ClipBoundary[0].y-S.y)*(P.x-S.x)/(P.x-S.y);
	}
	else
	{
		IntersectPt.x=ClipBoundary[0].x;
		IntersectPt.y=S.y+(ClipBoundary[0].x-S.x)*(P.x-S.y)/(P.x-S.x);
	}
}
void CPolygonView::Output(CPoint P,int Outlength,CPoint OutVertexArray[])
{
	        OutVertexArray[Outlength].x=P.x;
			OutVertexArray[Outlength].y=P.y;
			Outlength++;
}
