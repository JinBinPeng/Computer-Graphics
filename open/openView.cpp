// openView.cpp : implementation of the COpenView class
//

#include "stdafx.h"
#include "open.h"

#include "openDoc.h"
#include "openView.h"
#include "idtransdlg.h"
#include "scaledlg.h"
#include "rotatedlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COpenView

IMPLEMENT_DYNCREATE(COpenView, CView)

BEGIN_MESSAGE_MAP(COpenView, CView)
	//{{AFX_MSG_MAP(COpenView)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(IDM_TRANSFORM, OnTransform)
	ON_COMMAND(IDM_SCALE, OnScale)
	ON_COMMAND(IDM_RO, OnRo)
	ON_COMMAND(IDM_FUHE, OnFuhe)
	ON_COMMAND(IDM_FANLI, OnFanli)
	ON_COMMAND(IDM_FANLI1, OnFanli1)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COpenView construction/destruction

COpenView::COpenView()
{
	// TODO: add construction code here
 type=0;
 tx=0;
 ty=0;
 tz=0;
 sx=1;
 sy=1;
 sz=1;
}

COpenView::~COpenView()
{
}

BOOL COpenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
    cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);//opengl 环境初始化
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COpenView drawing

void COpenView::OnDraw(CDC* pDC)
{
	COpenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	switch (type)
	{
	case 1:movecube(tx,ty,tz);type=0;break;
	case 2:scalecube(sx,sy,sz);type=0;break;
	case 3:rotatecube(angle,rx,ry,rz);type=0;break;
	}
//	displaySolid();
/*	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);



glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(2,0,2,0,0,0,0,1,0);

glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(30, aspect, 0, 100.0);
glPushMatrix();
glTranslated(2,1,-6);
glutWireTeapot(0.5);
glPopMatrix();

glBegin(GL_POLYGON);
glVertex2f(-0.5,-0.5);
glVertex2f(-0.5,0.5);
glVertex2f(0.5,0.5);
glVertex2f(0.5,-0.5);
glEnd();

glPushMatrix();
glTranslated(1,1,0);
glutWireSphere(0.25,10,8);
glPopMatrix();

glPushMatrix();
glTranslated(1,0,1);
glutWireCone(0.2,0.5,10,8);
glPopMatrix();

glFlush();*/



}

/////////////////////////////////////////////////////////////////////////////
// COpenView printing

BOOL COpenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COpenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COpenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COpenView diagnostics

#ifdef _DEBUG
void COpenView::AssertValid() const
{
	CView::AssertValid();
}

void COpenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COpenDoc* COpenView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COpenDoc)));
	return (COpenDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COpenView message handlers

BOOL COpenView::SetWindowPixelFormat(HDC hDC)
{
PIXELFORMATDESCRIPTOR pixelDesc;
pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
pixelDesc.nVersion = 1;
pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DRAW_TO_BITMAP | PFD_SUPPORT_OPENGL |PFD_SUPPORT_GDI |PFD_STEREO_DONTCARE;
pixelDesc.iPixelType = PFD_TYPE_RGBA;
pixelDesc.cColorBits = 32; 
pixelDesc.cRedBits = 8;
pixelDesc.cRedShift = 16;
pixelDesc.cGreenBits = 8;
pixelDesc.cGreenShift = 8;
pixelDesc.cBlueBits = 8;
pixelDesc.cBlueShift = 0; 
pixelDesc.cAlphaBits = 0;
pixelDesc.cAlphaShift = 0;
pixelDesc.cAccumBits= 64; 
pixelDesc.cAccumRedBits = 16;
pixelDesc.cAccumGreenBits = 16;
pixelDesc.cAccumBlueBits = 16;
pixelDesc.cAccumAlphaBits= 0;
pixelDesc.cDepthBits = 32; 
pixelDesc.cStencilBits= 8;
pixelDesc.cAuxBuffers = 0; 
pixelDesc.iLayerType= PFD_MAIN_PLANE;
pixelDesc.bReserved = 0; 
pixelDesc.dwLayerMask= 0;
pixelDesc.dwVisibleMask= 0;
pixelDesc.dwDamageMask= 0;
m_GLPixelIndex = ChoosePixelFormat( hDC, &pixelDesc);
if (m_GLPixelIndex==0) // Let's choose a default index.
{
m_GLPixelIndex = 1; 
if (DescribePixelFormat(hDC, m_GLPixelIndex, sizeof
(PIXELFORMATDESCRIPTOR), &pixelDesc)==0)
{
return FALSE;
}
}
if (SetPixelFormat( hDC, m_GLPixelIndex, &pixelDesc)==FALSE)
{
return FALSE;
}
return TRUE;
}

int COpenView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
 HWND hWnd = GetSafeHwnd();
   HDC hDC = ::GetDC(hWnd);
  if (SetWindowPixelFormat(hDC)==FALSE) 
 return 0;
 if (CreateViewGLContext(hDC)==FALSE)
return 0;
return 0;
}


BOOL COpenView::CreateViewGLContext(HDC hDC)
{
m_hGLContext = wglCreateContext(hDC);
if (m_hGLContext == NULL)
{return FALSE; }
if (wglMakeCurrent(hDC, m_hGLContext)==FALSE)
{return FALSE;}
return TRUE;

}

void COpenView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	GLsizei width, height; 
width = cx; height = cy;
if (cy==0) aspect=(GLdouble)width;
else
aspect=(GLdouble)width/(GLdouble)height;
glViewport(0, 0, width, height);


}

void COpenView::displaySolid()
{
	glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
	GLfloat mat_ambient[]={1.0f,0.0f,0.0f,1.0f};
	GLfloat mat_diffuse[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
	GLfloat mat_shininess[]={50.0f};
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	GLfloat lightIntensity[]={0.7f,0.7f,0.7f,1.0f};
	GLfloat light_position[]={2.0f,6.0f,3.0f,0.0f};
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt=1.0;
	glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2.3,1.3,2,0,0.25,0,0.0,1,0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glTranslated(0.6,0.38,0.5);
	glRotated(30,0,1,0);
	glutSolidTeapot(0.5);
	glPopMatrix();


	glFlush();

}

void COpenView::OnTransform() 
{
	// TODO: Add your command handler code here
	IDTRANSDLG mydlg;
	if (mydlg.DoModal()==IDOK)
	{	UpdateData(true);
	    type=1;
		tx=mydlg.m_tx;  ty=mydlg.m_ty; tz=mydlg.m_tz;
	}
	Invalidate();

}

void COpenView::movecube(float tx, float ty, float tz)//平移操作
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt=1.0;
	glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,2,2,0,0,0,0.0,1,0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslated(tx,ty,tz);
	glutWireTeapot(0.5);
	glPopMatrix();
	glFlush();


}

void COpenView::OnScale() 
{
	// TODO: Add your command handler code here
	CScaleDlg mydlg;
	if (mydlg.DoModal()==IDOK)
	{	UpdateData(true);
	    type=2;
		sx=mydlg.m_sx;  sy=mydlg.m_sy; sz=mydlg.m_sz;
	}
	Invalidate();
}

void COpenView::scalecube(float sx, float sy, float sz)//缩放操作
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt=1.0;
	glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,2,2,0,0,0,0.0,1,0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glScaled(sx,sy,sz);
	glutWireTeapot(0.5);
	glPopMatrix();
	glFlush();

}

void COpenView::rotatecube(float angle, float rx, float ry, float rz)//旋转操作
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double winHt=1.0;
	glOrtho(-winHt*64/48,winHt*64/48,-winHt,winHt,0.1,100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,2,2,0,0,0,0.0,1,0);

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glRotated(angle,rx,ry,rz);
	glutWireTeapot(0.5);
	glPopMatrix();
	glFlush();

}

void COpenView::OnRo() 
{
	// TODO: Add your command handler code here
	CRotateDlg mydlg;
	if (mydlg.DoModal()==IDOK)
	{	UpdateData(true);
	    type=3;
		rx=mydlg.m_rx;  ry=mydlg.m_ry; rz=mydlg.m_rz;
		angle=mydlg.m_angle;
	}
	Invalidate();
}


void COpenView::displayWire()
{
  	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2*aspect,2*aspect,-2,2,0.1,100);
	glMatrixMode(GL_MODELVIEW);  
	glLoadIdentity();
	gluLookAt(2,2,2,0,0,0,0.0,1,0);
	glClear(GL_COLOR_BUFFER_BIT);

	//axis(0.5);
	//glPushMatrix();
	//glRotated(90,0,1,0);
	//axis(0.5);
	//glRotated(90,1,0,0);
	//axis(0.5);
	//glPopMatrix();

	glPushMatrix();
	glTranslated(0.5,0.5,0.5);
	glutWireCube(2);
	glPopMatrix();
	//请在下方添加你的代码
	glPushMatrix();
    glutWireTeapot(0.3);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,2);
	glRotated(45,0,0,0);
	glutWireCone(0.4,1,15,15);
	glPopMatrix();

    glPushMatrix();
	glTranslated(0,2,2);
	glutWireCube(0.5);
	glPopMatrix();
	
    glPushMatrix();
	glTranslated(2,2,0);
    glutWireSphere(0.5,10,10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,2,0);
    glutWireTorus(0.1,0.4,10,10);
	glPopMatrix();

	glPushMatrix();
	glTranslated(2,0,0);
	glScaled(0.3,0.3,0.3);
	glutWireDodecahedron();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0,0,2);
	glScaled(0.4,0.4,0.4);
	glutWireIcosahedron();
	glPopMatrix();

	glFlush();
}

void COpenView::OnFuhe() 
{
	// TODO: Add your command handler code here
	displayWire();
}

void COpenView::OnFanli() 
{
	// TODO: Add your command handler code here
	displaySolid();
}

void COpenView::OnFanli1() 
{
	// TODO: Add your command handler code here


}

void COpenView::axis(double length)
{
	glPushMatrix();
	
	glTranslated(0,0,length-0.2);
	glutWireCone(0.04,0.2,12,9);
	glPopMatrix();

}
