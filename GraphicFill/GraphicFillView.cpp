// GraphicFillView.cpp : implementation of the CGraphicFillView class
//

#include "stdafx.h"
#include "GraphicFill.h"

#include "GraphicFillDoc.h"
#include "GraphicFillView.h"
#include "time1.h"
#include <stack>  
using namespace std;  

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

typedef struct{
  int y,xl,xr;
}Span;
#define stack_size 100
Span S[stack_size];
int top=0;
void SetStackEmpty(){
  top=0;
}
bool isStackEmpty(){
  return top==0;
}
bool PushStack(Span *ps){
if(top<stack_size)
{
  S[top]=*ps;
  top++;
  return true;
}
else
return false;
}
bool PopStack(Span *ps){
if(top>0){
top--;
*ps=S[top];
return true;
}
else return false;
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView

IMPLEMENT_DYNCREATE(CGraphicFillView, CView)

BEGIN_MESSAGE_MAP(CGraphicFillView, CView)
	//{{AFX_MSG_MAP(CGraphicFillView)
	ON_COMMAND(ID_PENCOLOR, OnPencolor)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_Boundary, OnBoundary)
	ON_COMMAND(ID_FLOODFILL, OnFloodfill)
	ON_COMMAND(ID_EDGEFILL, OnEdgefill)
	ON_COMMAND(ID_EDGEMARKFILL, OnEdgemarkfill)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView construction/destruction

CGraphicFillView::CGraphicFillView()
{
	// TODO: add construction code here
pencolor=RGB(0,0,0);
boundarycolor=RGB(0,0,0);
isfill=0;

}

CGraphicFillView::~CGraphicFillView()
{
}

BOOL CGraphicFillView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView drawing

void CGraphicFillView::OnDraw(CDC* pDC)
{
	CGraphicFillDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	CRect urect;
    GetClientRect(&urect);//获取客户区大小
    CPoint c=urect.CenterPoint();//获取矩形区中心坐标
    clipwin=CRect(c.x-150,c.y-100,c.x+150,c.y+100);//记录裁剪窗口坐标
	a[0].x=260;
	a[0].y=270;
	a[1].x=300;
	a[1].y=150;
	a[2].x=240;
	a[2].y=180;
	a[3].x=200;
	a[3].y=150;
	a[4].x=200;
	a[4].y=220;
	a[5].x=240;
	a[5].y=220;
	pDC->Polygon(a,6);
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
	currentPos.Format("F:%d,%d",a[5].x,a[5].y);
    pDC->TextOut(10,160,currentPos);
   
	pDC->TextOut(a[0].x-10,a[0].y,"A");
	pDC->TextOut(a[1].x+10,a[1].y,"B");
	pDC->TextOut(a[2].x+5,a[2].y-25,"C");
	pDC->TextOut(a[3].x-10,a[3].y-15,"D");
	pDC->TextOut(a[4].x-10,a[4].y,"E");
	pDC->TextOut(a[5].x-10,a[5].y+5,"F");
    COLORREF r=pDC->GetPixel(currentpoint.x,currentpoint.y);
	if (isfill==1)
	{
		currentPos.Format("种子点:%d,%d",currentpoint.x,currentpoint.y);
	    pDC->TextOut(10,190,currentPos);
		
		if (suanfa==1) {watch b;boundaryFill4(currentpoint.x,currentpoint.y,pencolor,boundarycolor);}
		if (suanfa==2) {watch b;floodFill4(currentpoint.x,currentpoint.y,r,pencolor);}
		if (suanfa==3) {watch b;ScanLineFill4(currentpoint.x,currentpoint.y,r,pencolor);}
		if (suanfa==4) {watch b;boundaryFill4_stack(currentpoint.x,currentpoint.y,pencolor,boundarycolor);}
		isfill=0;
	}

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView printing

BOOL CGraphicFillView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGraphicFillView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGraphicFillView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView diagnostics

#ifdef _DEBUG
void CGraphicFillView::AssertValid() const
{
	CView::AssertValid();
}

void CGraphicFillView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGraphicFillDoc* CGraphicFillView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGraphicFillDoc)));
	return (CGraphicFillDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGraphicFillView message handlers

void CGraphicFillView::OnPencolor() 
{
	// TODO: Add your command handler code here
	CColorDialog colordlg;
	int ans=colordlg.DoModal();
	if (ans==IDOK)
	{
		pencolor=colordlg.GetColor();
	}
	
}

void CGraphicFillView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (isfill==1)
	{
		currentpoint=point;
		Invalidate();
        
	}
	CView::OnLButtonDown(nFlags, point);
}

void CGraphicFillView::OnBoundary() 
{
	// TODO: Add your command handler code here
	isfill=1;
	suanfa=1;
}

void CGraphicFillView::boundaryFill4(int x, int y, COLORREF fill, COLORREF boundary)
{
	//函数参数说明：x,y为种子点坐标，fill为填充色，boundary为边界色
	CClientDC dc(this);
	int color = dc.GetPixel(x,y);
	if(color != fill && color != boundary){
		dc.SetPixel(x,y,fill);
		boundaryFill4(x,y+1,fill,boundary);
		boundaryFill4(x,y-1,fill,boundary);
		boundaryFill4(x+1,y,fill,boundary);
		boundaryFill4(x-1,y,fill,boundary);
	}
}

void CGraphicFillView::OnFloodfill() 
{
	// TODO: Add your command handler code here
	isfill=1;
	suanfa=2;
}

void CGraphicFillView::floodFill4(int x, int y, COLORREF oldcolor, COLORREF newcolor)
{
	//函数参数说明：x,y为种子点坐标，oldcolor为区域的原色，newcolor为填充色
	CClientDC dc(this);
	int color = dc.GetPixel(x,y);
	if(color == oldcolor){
		dc.SetPixel(x,y,newcolor);
		floodFill4(x,y+1,oldcolor,newcolor);
		floodFill4(x,y-1,oldcolor,newcolor);
		floodFill4(x+1,y,oldcolor,newcolor);
		floodFill4(x-1,y,oldcolor,newcolor);
	}
}

void CGraphicFillView::OnEdgefill() 
{
	// TODO: Add your command handler code here
	isfill=1;
	suanfa=3;
}

void CGraphicFillView::ScanLineFill4(int x, int y, COLORREF oldcolor, COLORREF newcolor)
{
	//函数参数说明：x,y为种子点坐标，oldcolor为区域的原色，newcolor为填充色
	//??????:x,y??????,oldcolor??????,newcolor????
 Span span;
 span.y = y;
 span.xl = x; 
 CClientDC dc(this);
 while (dc.GetPixel( span.xl, span.y) == oldcolor)
 {
  dc.SetPixel( span.xl, span.y, newcolor);
  span.xl--;
 }
 if (span.xl == x)//not a seed point actually
  return;
 else
  span.xl++;//compansate
 span.xr = x + 1;
 while (dc.GetPixel( span.xr, span.y) == oldcolor)
 {
  dc.SetPixel( span.xr, span.y, newcolor);
  span.xr++;
 }
 if (span.xr == x + 1)//cannot extend to right
  span.xr = x;
 else
  span.xr--;//compansate

 SetStackEmpty();
 PushStack(&span);

 while (!isStackEmpty())
 {
  PopStack(&span);
  Span S;//new span
  {
   S.y = span.y + 1;
   S.xl = span.xl;
   bool xLeftNotSet = false;
   while (dc.GetPixel( S.xl, S.y) == oldcolor)
   {
    S.xl--;
   }
   if (S.xl == span.xl)//xLeft is not set
    xLeftNotSet = true;
   else
    S.xl++;//compansate
   int i = S.xl;
   while (i <= span.xr)
   {
    while (dc.GetPixel( i, S.y) == oldcolor)
    {
     if (xLeftNotSet)
     {
      S.xl = i;
      xLeftNotSet = false;
     }
     dc.SetPixel( i, S.y, newcolor);
     i++;
    }
    if (i > S.xl)
    {
     S.xr = i - 1;
     PushStack(&S);
     xLeftNotSet = true;
    }
    while (i <= span.xr && dc.GetPixel( i, S.y) != oldcolor)
    {
     i++;
    }
   }
  }
  {//similar to above
   S.y = span.y - 1;
   S.xl = span.xl;
   bool xLeftNotSet = false;
   while (dc.GetPixel(S.xl, S.y) == oldcolor)
   {
    S.xl--;
   }
   if (S.xl == span.xl)//xLeft is not set
    xLeftNotSet = true;
   else
    S.xl++;//compansate
   int i = S.xl;
   while (i <= span.xr)
   {
    while (dc.GetPixel( i, S.y) == oldcolor)
    {
     if (xLeftNotSet)
     {
      S.xl = i;
      xLeftNotSet = false;
     }
     dc.SetPixel( i, S.y, newcolor);
     i++;
    }
    if (i > S.xl)
    {
     S.xr = i - 1;
     PushStack(&S);
     xLeftNotSet = true;
    }
    while (i <= span.xr && dc.GetPixel( i, S.y) != oldcolor)
    {
     i++;
    }
   }
  }
 }

}



void CGraphicFillView::OnEdgemarkfill() 
{
	// TODO: Add your command handler code here
		isfill=1;
	   suanfa=4;
}

void CGraphicFillView::boundaryFill4_stack(int x, int y, COLORREF fill, COLORREF boundary)
{
	CClientDC dc(this);
    stack <CPoint> ptStack;//?????????? 
	 CPoint ptCurrent = CPoint(x, y);    //?????????????  
    ptStack.push( ptCurrent );          //?????????  
    while ( !ptStack.empty() )  
    {  		
        ptCurrent = ptStack.top(); 
		int color=dc.GetPixel(ptCurrent.x,ptCurrent.y);
		if(color!=fill&&color!=boundary)
        dc.SetPixel( ptCurrent.x,ptCurrent.y, fill ); // ????  
        ptStack.pop();  // ??   
        CPoint ptArround[ 4 ];  
        ptArround[ 0 ] = CPoint( ptCurrent.x - 1, ptCurrent.y );  
        ptArround[ 1 ] = CPoint( ptCurrent.x + 1, ptCurrent.y );  
        ptArround[ 2 ] = CPoint( ptCurrent.x, ptCurrent.y - 1 );  
        ptArround[ 3 ] = CPoint( ptCurrent.x, ptCurrent.y + 1 );            
        // ??????????????  
        for ( int i = 0; i < 4; i ++ )  
        {  
            if( dc.GetPixel( ptArround[ i ] ) != fill )  
            {  
            ptStack.push( ptArround[i] );  // ??  
            }  
        }  

    }  
}

