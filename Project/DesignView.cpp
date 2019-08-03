// DesignView.cpp : implementation of the CDesignView class
//

#include "stdafx.h"
#include "Design.h"

#include "DesignDoc.h"
#include "DesignView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDesignView

IMPLEMENT_DYNCREATE(CDesignView, CView)

BEGIN_MESSAGE_MAP(CDesignView, CView)
	//{{AFX_MSG_MAP(CDesignView)
	ON_COMMAND(ID_Line, OnLine)
	ON_UPDATE_COMMAND_UI(ID_Line, OnUpdateLine)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_Ellipse, OnEllipse)
	ON_COMMAND(ID_Rectangle, OnRectangle)
	ON_COMMAND(ID_PENCOLOR, OnPencolor)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDesignView construction/destruction

CDesignView::CDesignView()
{
	// TODO: add construction code here
	m_startRect=FALSE;
	m_startPoint=0;
	m_OldPoint=0;
	m_drawType=0;
	//初始化m_HCross为十字光标
	m_HCross=AfxGetApp()->LoadStandardCursor(IDC_CROSS);  

}

CDesignView::~CDesignView()
{
}

BOOL CDesignView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDesignView drawing

void CDesignView::OnDraw(CDC* pDC)
{
	CDesignDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CDesignView printing

BOOL CDesignView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDesignView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDesignView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CDesignView diagnostics

#ifdef _DEBUG
void CDesignView::AssertValid() const
{
	CView::AssertValid();
}

void CDesignView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDesignDoc* CDesignView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDesignDoc)));
	return (CDesignDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDesignView message handlers

void CDesignView::OnLine() 
{
	// TODO: Add your command handler code here
	m_drawType=2; 
}

void CDesignView::OnUpdateLine(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
		
}

void CDesignView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_startRect=TRUE; 
	m_startPoint=point; 
	m_OldPoint=point;
	::SetCursor(m_HCross);
	
	CView::OnLButtonDown(nFlags, point);
}

void CDesignView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_startRect=FALSE;
	::ClipCursor(NULL);
	CClientDC dc(this);
	//  dc.SetROP2(R2_NOT); 
	dc.SelectStockObject(NULL_BRUSH); 
	switch(m_drawType)
	{
	case 1: 

		dc.Rectangle(CRect(m_startPoint,m_OldPoint));
	
		dc.Rectangle(CRect(m_startPoint,point));
	
		break;
	
	case 2:  
	
		dc.MoveTo(m_startPoint);
		dc.LineTo(m_OldPoint);
	
		dc.MoveTo(m_startPoint);
		dc.LineTo(point);
		break;
	case 3:  
		dc.Ellipse(CRect(m_startPoint,m_OldPoint));
		dc.Ellipse(CRect(m_startPoint,point));
		break;
	case 4: 
		dc.Ellipse(CRect(m_startPoint,m_OldPoint));
		dc.Ellipse(CRect(m_startPoint,point));
		break;
	case 5:  
		dc.SetPixel(point,RGB(0,0,0));
		break;
	}
    
		
		CView::OnLButtonUp(nFlags, point);
}

void CDesignView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CClientDC dc(this);
	dc.SetROP2(R2_NOT);
	dc.SetROP2(R2_NOT);
	dc.SelectStockObject(NULL_BRUSH);

	if(TRUE==m_startRect)
	{
		switch(m_drawType)
		{
			case 1:
				::SetCursor(m_HCross);
				dc.Rectangle(CRect(m_startPoint,m_OldPoint));
				dc.Rectangle(CRect(m_startPoint,point));
				m_OldPoint=point;
				break;
			
			case 2: 
				::SetCursor(m_HCross);
				dc.MoveTo(m_startPoint);
				dc.LineTo(m_OldPoint);
				dc.MoveTo(m_startPoint);
				dc.LineTo(point);
				m_OldPoint=point;
				break;
			
			case 3:  
				::SetCursor(m_HCross);
				m_OldPoint.y=m_OldPoint.x-m_startPoint.x+m_startPoint.y;
				dc.Ellipse(CRect(m_startPoint,m_OldPoint));
				point.y=point.x-m_startPoint.x+m_startPoint.y;
				dc.Ellipse(CRect(m_startPoint,point));
				m_OldPoint=point;
				break;
			
			case 4:  
				::SetCursor(m_HCross);
				dc.Ellipse(CRect(m_startPoint,m_OldPoint));
				dc.Ellipse(CRect(m_startPoint,point));
				m_OldPoint=point;
				break;
			
			case 5: 
				break;
		}
	}


	CView::OnMouseMove(nFlags, point);
}


void CDesignView::OnEllipse() 
{
	// TODO: Add your command handler code here
	m_drawType=4; 
}

void CDesignView::OnRectangle() 
{
	// TODO: Add your command handler code here
	m_drawType=1;
}

void CDesignView::OnPencolor() 
{
	// TODO: Add your command handler code here
		CColorDialog colordlg;
	int ans=colordlg.DoModal();
	if (ans==IDOK)
	{
		pencolor=colordlg.GetColor();
	}
}
