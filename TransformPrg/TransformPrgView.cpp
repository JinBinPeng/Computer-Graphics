// TransformPrgView.cpp : implementation of the CTransformPrgView class
//

#include "stdafx.h"
#include "TransformPrg.h"

#include "TransformPrgDoc.h"
#include "TransformPrgView.h"

#include "Line.h"//ֱ����
#include "Mainfrm.h"//�����ͷ�ļ�
#define ROUND(a) int(a+0.5)//��������
#include "math.h"//��ѧͷ�ļ�
#define  PI 3.14159265//Բ����


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
	SetTimer(1,50,NULL);//���ö�ʱ��
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
	CRect rect;//����ͻ���
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	pDC->SetMapMode(MM_ANISOTROPIC);//pDC�Զ�������ϵ
	pDC->SetWindowExt(rect.Width(),rect.Height());//���ô��ڷ�Χ
	pDC->SetViewportExt(rect.Width(),-rect.Height());//x��ˮƽ���ң�y�ᴹֱ����
	pDC->SetViewportOrg(rect.Width()/2,rect.Height()/2);//��Ļ����Ϊԭ��
	CDC MemDC;//�ڴ�DC
	CBitmap NewBitmap,*pOldBitmap;//�ڴ��г���ͼ�����ʱλͼ
	MemDC.CreateCompatibleDC(pDC);//��������ĻpDC���ݵ�MemDC 
	NewBitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());//��������λͼ 
	pOldBitmap=MemDC.SelectObject(&NewBitmap); //������λͼѡ��MemDC 
	MemDC.SetMapMode(MM_ANISOTROPIC);//MemDC�Զ�������ϵ
	MemDC.SetWindowExt(rect.Width(),rect.Height());
	MemDC.SetViewportExt(rect.Width(),-rect.Height());
	MemDC.SetViewportOrg(rect.Width()/2,rect.Height()/2);
	ReadPoint();//����ͼ�ζ�������
	tran.Translate(translateX,translateY);//ƽ�Ʊ任
	tran.Rotate(rotate,CP2(translateX,translateY));//�������������ת�任
	tran.Scale(scale,scale,CP2(translateX,translateY));//����������ı����任
	DrawObject(&MemDC);
	BorderCheck();	
	pDC->BitBlt(-rect.Width()/2,-rect.Height()/2,rect.Width(),rect.Height(),&MemDC,-rect.Width()/2,-rect.Height()/2,SRCCOPY);//���ڴ�λͼ��������Ļ
	MemDC.SelectObject(pOldBitmap);//�ָ�λͼ
	NewBitmap.DeleteObject();//ɾ��λͼ
	MemDC.DeleteDC();//ɾ��MemDC
	ReleaseDC(pDC);//�ͷ�DC
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
	P[degree].x=0;P[degree].y=0;//ͼ�����ĵ�
	tran.SetMat(P,degree+1);
}


void CTransformPrgView::BorderCheck()
{
	double TempR=R*scale;
	CRect rect;//����ͻ���
	GetClientRect(&rect);//��ÿͻ����Ĵ�С
	int nWidth=rect.Width()/2;
	int nHeight=rect.Height()/2;
	if(fabs(P[degree].x)+TempR>nWidth)
	{
		directionX*=-1;
		translateX+=fabs(fabs(P[degree].x)+TempR-nWidth)*directionX;//�ж�����ˮƽԽ��
	}
	if(fabs(P[degree].y)+TempR>nHeight)
	{
		directionY*=-1;
		translateY+=fabs(fabs(P[degree].y)+TempR-nHeight)*directionY;//�ж����崹ֱԽ��
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
