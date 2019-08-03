// lineclipView.cpp : implementation of the CLineclipView class
//

#include "stdafx.h"
#include "lineclip.h"
#include "mainfrm.h"
#include "lineclipDoc.h"
#include "lineclipView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define LEFT 1
#define RIGHT 2
#define BOTTOM 4
#define TOP 8
/////////////////////////////////////////////////////////////////////////////
// CLineclipView

IMPLEMENT_DYNCREATE(CLineclipView, CView)

BEGIN_MESSAGE_MAP(CLineclipView, CView)
	//{{AFX_MSG_MAP(CLineclipView)
	ON_COMMAND(ID_BUTTON32772, OnButton32772)
	ON_UPDATE_COMMAND_UI(ID_BUTTON1, OnUpdateButton1)
	ON_COMMAND(ID_BUTTON1, OnButton1)
	ON_UPDATE_COMMAND_UI(ID_BUTTON32772, OnUpdateButton32772)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_POS, OnUpdatePos)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_BCOHAN, OnBcohan)
	ON_COMMAND(ID_BLIANG, OnBliang)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineclipView construction/destruction

CLineclipView::CLineclipView()
{
	// TODO: add construction code here
draw=0;
drawing=0;
clip="";

}

CLineclipView::~CLineclipView()
{
}

BOOL CLineclipView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView drawing

void CLineclipView::OnDraw(CDC* pDC)
{
	CLineclipDoc* pDoc = GetDocument();
	
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CRect urect;
    GetClientRect(&urect);//获取客户区大小
    CPoint c=urect.CenterPoint();//获取矩形区中心坐标
    clipwin=CRect(c.x-150,c.y-100,c.x+150,c.y+100);//记录裁剪窗口坐标
    pDC->Rectangle(&clipwin);//绘制裁剪窗口

	CString currentPos;
	currentPos.Format("left:%d",clipwin.left);
    pDC->TextOut(10,10,currentPos);
	currentPos.Format("right:%d",clipwin.right);
    pDC->TextOut(10,40,currentPos);
	currentPos.Format("bottom:%d",clipwin.bottom);
    pDC->TextOut(10,70,currentPos);
	currentPos.Format("top:%d",clipwin.top);
    pDC->TextOut(10,100,currentPos);
    wxl=clipwin.left;
	wxr=clipwin.right;
	wyt=clipwin.bottom;
	wyb=clipwin.top;
	if (clip=="cohan")
	{		
	    pDC->TextOut(10,200,text);
		cohen();

	}
	else if (clip=="liang")
	{
	    pDC->TextOut(10,200,text);
		liang();
	}
	else if (clip="none")
	{
		pDC->MoveTo(startpoint);
		pDC->LineTo(endpoint);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView printing

BOOL CLineclipView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLineclipView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLineclipView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLineclipView diagnostics

#ifdef _DEBUG
void CLineclipView::AssertValid() const
{
	CView::AssertValid();
}

void CLineclipView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLineclipDoc* CLineclipView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLineclipDoc)));
	return (CLineclipDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLineclipView message handlers

void CLineclipView::OnButton32772() 
{
	// TODO: Add your command handler code here
	draw=0;
	
}

void CLineclipView::OnUpdateButton1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (draw==1)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void CLineclipView::OnButton1() 
{
	// TODO: Add your command handler code here
draw=1;	
drawing=1;
}

void CLineclipView::OnUpdateButton32772(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if (draw==0)
		pCmdUI->SetCheck(1);
	else
		pCmdUI->SetCheck(0);
}

void CLineclipView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (drawing)
	{

		SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	    SetCapture();
	    m_prev=point;
		m_current=point;
	}
	CView::OnLButtonDown(nFlags, point);
}

void CLineclipView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
   	if (GetCapture()!=this)
		return;
   if (drawing)
   {
	   clip="none";
	startpoint=m_prev;
	endpoint=point;
    drawing=0;
	draw=0;
	Invalidate();
   }
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}

void CLineclipView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	 currentPos.Format("X:%d,Y:%d",point.x,point.y);
	 if (GetCapture()!=this)
		return;
	if (drawing)
	{
	SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	 CDC* pDC = GetDC();
     int oldmode =  pDC ->GetROP2();
     pDC ->SetROP2(R2_NOT);//
	pDC->MoveTo(m_prev);
	pDC->LineTo(m_current);
    pDC ->SetROP2(R2_NOT);
	pDC->MoveTo(m_prev);
	pDC->LineTo(point);
	m_current=point;
	}

		
	CView::OnMouseMove(nFlags, point);
}
void CLineclipView::OnUpdatePos(CCmdUI *pCmdUI)
{
	 pCmdUI->Enable();
    pCmdUI->SetText(currentPos);      

}
void CLineclipView::OnBcohan() 
{
	// TODO: Add your command handler code here
	text="编码裁剪算法";
	clip="cohan";
	Invalidate();
}

void CLineclipView::OnBliang() 
{
	// TODO: Add your command handler code here
	text="梁友栋裁剪算法";
	clip="liang";
	Invalidate();
}

void CLineclipView::cohen()
{
	int x,y;
	int code1,code2,code;
	code1=encode(startpoint.x,startpoint.y);
	code2=encode(endpoint.x,endpoint.y);
	while(code1!=0 || code2!=0)
	{
		if((code1 & code2) != 0) return;
		if(code1 != 0) code=code1;
		else code=code2;
		if((LEFT & code) !=0)
		{
			x=wxl;
			y=startpoint.y+(endpoint.y-startpoint.y)*(wxl-startpoint.x)/(endpoint.x-startpoint.x);
		}
		else if((RIGHT & code) !=0)
		{
			x=wxr;
			y=startpoint.y+(endpoint.y-startpoint.y)*(wxr-startpoint.x)/(endpoint.x-startpoint.x);
		}
		else if((BOTTOM & code) !=0)
		{
			y=wyb;
			x=startpoint.x+(endpoint.x-startpoint.x)*(wyb-startpoint.y)/(endpoint.y-startpoint.y);
		}
		else if((TOP & code) !=0)
		{
			y=wyt;
			x=startpoint.x+(endpoint.x-startpoint.x)*(wyt-startpoint.y)/(endpoint.y-startpoint.y);
		}
		if(code == code1)
		{startpoint.x=x;startpoint.y=y;code1=encode(x,y);}
		else
		{endpoint.x=x;endpoint.y=y;code2=encode(x,y);}
	}
	displayline(startpoint.x,startpoint.y,endpoint.x,endpoint.y);
}

void CLineclipView::liang()
{
	float dx,dy,u1,u2;
	u1=0;u2=1;
	dx=endpoint.x-startpoint.x;
	dy=endpoint.y-startpoint.y;
	if(ClipT(-dx,startpoint.x-wxl,&u1,&u2))
	if(ClipT(dx,wxr-startpoint.x,&u1,&u2))
	if(ClipT(-dy,startpoint.y-wyb,&u1,&u2))
	if(ClipT(dy,wyt-startpoint.y,&u1,&u2))
		displayline(startpoint.x+u1*dx,startpoint.y+u1*dy,startpoint.x+u2*dx,startpoint.y+u2*dy);
}

int CLineclipView::encode(int x, int y)
{
	int c=0;
	if(x<wxl) c|=LEFT;
	if(x>wxr) c|=RIGHT;
	if(y<wyb) c|=BOTTOM;
	if(y>wyt) c|=TOP;
    return c;
}

BOOL CLineclipView::ClipT(float p, float q, float *u1, float *u2)
{
  float r;
  if(p<0)
  {
	  r=q/p;
	  if(r>*u2)
		  return FALSE;
	  if(r>*u1)
		  *u1=r;
  }
  else if(p>0)
  {
	  r=q/p;
      if(r<*u1)
		  return FALSE;
	  if(r<*u2)
		  *u2=r;
  }
  else return(q>=0);
  return TRUE;
}

void CLineclipView::displayline(int x1, int y1, int x2, int y2)
{
	CClientDC dc(this);
	dc.MoveTo(x1,y1);
	dc.LineTo(x2,y2);

}
