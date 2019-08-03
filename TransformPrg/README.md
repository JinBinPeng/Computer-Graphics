#### 实验目的：

1、掌握二维几何变换的平移、比例、旋转变换矩阵

2、掌握矩阵乘法的编程实现

3、掌握相对于任意参考点的比例变换和旋转变换

4、掌握定时器的使用方法

5、掌握边界碰撞检测方法

6、掌握静态切分视图框架的设计方法

#### 实验要求：

*   .使用静态切分视图，将窗口分为左右窗格。左窗格为继承于CFormView类的表单视图类CLeftPortion，右窗格为一般视图类CTestView。
*   .左窗格提供代表"图形顶点数"（4、8、16和32）、"平移变换"（x方向和y方向）、"旋转变换"（逆时针和顺时针）和"比例变换"（放大和缩小）的滑动条，用于控制右窗格内的图形变化。
*   .右窗格内以屏幕客户区中心为图形的几何中心，绘制图形顶点数从4变化为8、16和32的正多边形。为了表达图形的旋转，多边形的每个顶点和图形中心使用直线连接。
*   .使用双缓冲技术控制图形在右窗格内的无闪烁运动。设定屏幕背景色为黑色，图形颜色为白色。
*   .使用客户区边界检测技术，改变图形在右窗格内和客户区边界碰撞后的运动方向

#### 效果图：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-fcaf80d22d651691.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

#### 实验步骤：

**建立单文档MFC程序，并将工程命名为：`TransformPrg.dsw`，将实验所需的类的实现文件**

#### 第一部分：建立划分左右窗格的静态切分视图框架

将文档窗口划分为两大区域：左窗格为继承于`CFormView`类的表单视图类`CLeftPortion`，右窗格为一般视图类`CTestView`。

**1.在resourceView的面板中，新建默认ID为`IDD_DIALOG1`的对话框资源。打开对话框属性，设置`Style`为`Child`，`Border`为`None`。**

![image.png](https://upload-images.jianshu.io/upload_images/4630295-6e189666bd2d5836.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

**2.为对话框增加4个`groupBox`控件，7个`StaticText`控件和5个`Slider`控件。如图所示。滑块控件的标识符从上至下依次为`IDC_SLIDER1~IDC_SLIDER5`。滑块的styles属性中，将`tick marks`以及`auto ticks`设置为选中。将`caption`为"三角形面片数：8"的`static text`控件的ID设置为`IDC_CURFACE`。**

控件设置

![image.png](https://upload-images.jianshu.io/upload_images/4630295-67e114da83f38909.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

滑块的style属性

![image.png](https://upload-images.jianshu.io/upload_images/4630295-9774ac11acb8e54f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

继承于表单类的对话框

![image.png](https://upload-images.jianshu.io/upload_images/4630295-a77f2ef1c9b69c1a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


**3.双击对话框，创建继承于`CFormView`类的`CLeftPortion`类，如上图所示。**

**4.在`CMainFrame`框架窗口类中声明一个`CSplitterWnd`类的成员变量m_wndSplitter。**

**5.使用类向导，为`CMainFrame`类添加`OnCreateClient`函数**

![image.png](https://upload-images.jianshu.io/upload_images/4630295-95409ee203e36ddd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

**6.在OnCreateClient函数中调用CSplitterWnd类的成员函数CreateStatic创建静态切分窗格，并调用CreateView为每个窗格创建视图窗口。请将原有OnCreateClient中的代码删除，添加以下部分代码：**

```
BOOL CMainFrame::OnCreateClient( LPCREATESTRUCT /*lpcs*/,
				 CCreateContext* pContext )
{
	m_wndSplitter.CreateStatic( this, 1, 2 ); /* 产生1×2的静态切分窗格 */
	m_wndSplitter.CreateView( 0, 0, RUNTIME_CLASS( CLeftPortion ), CSize( 220, 600 ), pContext );
	m_wndSplitter.CreateView( 0, 1, RUNTIME_CLASS( CTransformPrgView ), CSize( 520, 600 ), pContext );
	return(TRUE);
}
```

请在`MainFrm.cpp`中包含必要的头文件：

```
#include "leftportion.h"
#include "TransformPrgDoc.h"
#include "TransformPrgview.h"
```

#### 第二部分：为左窗格视图的控件增加消息映射

**1.控件的数据交换和数据校验**

控件的数据交换是将控件和数据成员变量相连接，用于获得控件当前的值。请根据下表建立控件变量：

| ID | 含义 | 变量类别 | 变量类型 | 变量 |
| --- | --- | --- | --- | --- |
| IDC_CURFACE | 图形面片数 | Control | CStatic | m_curface |
| IDC_SLIDER1 | 图形顶点数 | Control | CSliderCtrl | m_degree |
| IDC_SLIDER2 | 水平位移 | Control | CSliderCtrl | m_translateX |
| IDC_SLIDER3 | 垂直位移 | Control | CSliderCtrl | m_translateY |
| IDC_SLIDER4 | 旋转角度 | Control | CSliderCtrl | m_rotate |
| IDC_SLIDER5 | 缩放系数 | Control | CSliderCtrl | m_scale |

![image.png](https://upload-images.jianshu.io/upload_images/4630295-80d0e2ca28e562fc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

**2.添加`OnInitialUpdate`消息映射函数**

为了设置滑动条控件的初始值，需要在`CLeftPortion`类内部添加`OnInitialUpdate`消息映射函数，如图所示：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-8786721d8efde0cf.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

添加的代码如下：
```
void CLeftPortion::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	/*
	 * TODO: Add your specialized code here and/or call the base class
	 * 设置左窗格滑动条的范围及初始值
	 */
	m_degree.SetRange( 1, 4, TRUE );
	m_degree.SetPos( 2 );
	m_translateX.SetRange( 0, 10, TRUE );
	m_translateX.SetPos( 6 );
	m_translateX.SetTicFreq( 2 );
	m_translateX.SetPageSize( 2 );
	m_translateY.SetRange( 0, 10, TRUE );
	m_translateY.SetPos( 2 );
	m_translateY.SetTicFreq( 2 );
	m_translateY.SetPageSize( 2 );
	m_rotate.SetRange( -10, 10, TRUE );
	m_rotate.SetPos( 5 );
	m_rotate.SetTicFreq( 5 );
	m_rotate.SetPageSize( 5 );
	m_scale.SetRange( -2, 2, TRUE );
	m_scale.SetPos( 0 );
	CString str( "" );
	str.Format( "三角形面片数：%d", (int(pow( 2, m_degree.GetPos() + 1 ) ) ) );
	m_curface.SetWindowText( str );
	UpdateData( FALSE );
}
```

滑动条控件的属性设置包括设置活动条范围的`SetRange`函数，设置滑动块位置的`SetPos`，设置刻度线位置的`SetTicFreq`和设置滑动条控件的页大小的`SetPageSize`

请在`leftportion.cpp`中包含必要的头文件：`#include "math.h"`

**3.添加`WM_HSCROLL`消息映射函数**

为了判断用户操作了哪个滑动块，需要在`CLeftPortion`类中响应`WM_HSCROLL`消息，如图所示：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-3bbad980fb8cf73e.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

代码如下：

```
void CLeftPortion::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	/* TODO: Add your message handler code here and/or call default */
	CTransformPrgDoc *pDoc = (CTransformPrgDoc *) CFormView::GetDocument();
	UpdateData();
	switch ( m_degree.GetPos() )
	{
	case 1:
		pDoc->m_degree = 4;
		break;
	case 2:
		pDoc->m_degree = 8;
		break;
	case 3:
		pDoc->m_degree = 16;
		break;
	case 4:
		pDoc->m_degree = 32;
		break;
	}
	pDoc->m_translateX	= m_translateX.GetPos();
	pDoc->m_translateY	= m_translateY.GetPos();
	pDoc->m_rotate		= m_rotate.GetPos();
	switch ( m_scale.GetPos() )
	{
	case 2:
		pDoc->m_scale = 3.0;
		break;
	case 1:
		pDoc->m_scale = 2.0;
		break;
	case 0:
		pDoc->m_scale = 1.0;
		break;
	case -1:
		pDoc->m_scale = 0.5;
		break;
	case -2:
		pDoc->m_scale = 0.3;
		break;
	}
	CString str( "" );
	str.Format( "三角形面片数：%d", (int(pow( 2, m_degree.GetPos() + 1 ) ) ) );
	m_curface.SetWindowText( str );
	UpdateData( FALSE );

	CFormView::OnHScroll( nSBCode, nPos, pScrollBar );
}
```

**当拖动任一水平滑动条，都执行`OnHScorll`函数，先获取`CTransformPrgView`类的文档指针`pDoc`，然后将控件的值转换为文档数据。`UpdateData(true)`表示将控件中的内容输入给它的数据成员变量。`UpdateData(false)`表示将数据成员的值输出到控件中，让滑块移动到指定位置。**

请在`leftportion.cpp`中包含必要的头文件：`#include "TransformPrgDoc.h"`


#### 第三部分：通过文档类实现数据交换

**1.设计`CTransformPrgDoc`类**

**左右视图的通信通过`CTransformPrgDoc`类实现。在`TransformPrgDoc.h`头文件中增加以下声明：**

```
/* Attributes */
public:
int	m_degree;
double	m_translateX;
double	m_translateY;
double	m_rotate;
double	m_scale;
```

在构造函数中完成数据的初始化：

```
CTransformPrgDoc::CTransformPrgDoc()
{
	/* TODO: add one-time construction code here */
	m_degree	= 8;
	m_translateX	= 6;
	m_translateY	= 2;
	m_rotate	= 5;
	m_scale		= 1;
}
```

**2.设计包含齐次坐标的二维点类CP2**

在工程文件中导入`p2.cpp`，`p2.h`

**3.设计二维几何变换类**

复合旋转变换矩阵：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-fc0dadc75cdf535b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

复合比例变换矩阵

![image.png](https://upload-images.jianshu.io/upload_images/4630295-e132c2485739a447.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

二维几何变换类CTransForm: 在工程文件中导入`transfom.cpp`，`transform.h`

#### 第四部分：在右窗格绘制动态二维图形

**1.设计双缓冲**

双缓冲技术可以消除动画过程中的屏幕闪烁。双缓冲技术是现在`MemDC`中绘图，然后用`BitBlt`函数将图形复制到`pDC`中，同时禁止背景刷新，从而消除了闪烁。函数中用到的`ReadPoint`是计算图形顶点坐标函数，每次图形异动前，都重新计算顶点坐标值。比例变换以及旋转变换采用相对于任意参考点的变换。

**在`CTransformPrgView`类中增加成员函数：`void DoubleBuffer()`，并增加代码：**

```
void CTransformPrgView::DoubleBuffer()
{
	CDC	* pDC = GetDC();
	CRect	rect;                                                                                                                                   /* 定义客户区 */
	GetClientRect( &rect );                                                                                                                         /* 获得客户区的大小 */
	pDC->SetMapMode( MM_ANISOTROPIC );                                                                                                              /* pDC自定义坐标系 */
	pDC->SetWindowExt( rect.Width(), rect.Height() );                                                                                               /* 设置窗口范围 */
	pDC->SetViewportExt( rect.Width(), -rect.Height() );                                                                                            /* x轴水平向右，y轴垂直向上 */
	pDC->SetViewportOrg( rect.Width() / 2, rect.Height() / 2 );                                                                                     /* 屏幕中心为原点 */
	CDC	MemDC;                                                                                                                                  /* 内存DC */
	CBitmap NewBitmap, *pOldBitmap;                                                                                                                 /* 内存中承载图像的临时位图 */
	MemDC.CreateCompatibleDC( pDC );                                                                                                                /* 建立与屏幕pDC兼容的MemDC */
	NewBitmap.CreateCompatibleBitmap( pDC, rect.Width(), rect.Height() );                                                                           /* 创建兼容位图 */
	pOldBitmap = MemDC.SelectObject( &NewBitmap );                                                                                                  /* 将兼容位图选入MemDC */
	MemDC.SetMapMode( MM_ANISOTROPIC );                                                                                                             /* MemDC自定义坐标系 */
	MemDC.SetWindowExt( rect.Width(), rect.Height() );
	MemDC.SetViewportExt( rect.Width(), -rect.Height() );
	MemDC.SetViewportOrg( rect.Width() / 2, rect.Height() / 2 );
	ReadPoint();                                                                                                                                    /* 计算图形顶点坐标 */
	tran.Translate( translateX, translateY );                                                                                                       /* 平移变换 */
	tran.Rotate( rotate, CP2( translateX, translateY ) );                                                                                           /* 相对于任意点的旋转变换 */
	tran.Scale( scale, scale, CP2( translateX, translateY ) );                                                                                      /* 相对于任意点的比例变换 */
	DrawObject( &MemDC );
	BorderCheck();
	pDC->BitBlt( -rect.Width() / 2, -rect.Height() / 2, rect.Width(), rect.Height(), &MemDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY );      /* 将内存位图拷贝到屏幕 */
	MemDC.SelectObject( pOldBitmap );                                                                                                               /* 恢复位图 */
	NewBitmap.DeleteObject();                                                                                                                       /*删除位图 */
	MemDC.DeleteDC();                                                                                                                               /*删除MemDC */
	ReleaseDC( pDC );                                                                                                                               /* 释放DC */
	if ( P != NULL )
	{
		delete[]P;
		P = NULL;
	}
}
```

**2.读入图形顶点**

根据图形顶点的个数，先计算圆上各点的等分角，然后计算每个顶点的坐标值，最后计算图形中心点坐标。

在`CTransformPrgView`类中增加成员函数：`void ReadPoint()`，并增加代码：

```
void CTransformPrgView::DoubleBuffer()
{
	CDC	* pDC = GetDC();
	CRect	rect;                                                                                                                                   /* 定义客户区 */
	GetClientRect( &rect );                                                                                                                         /* 获得客户区的大小 */
	pDC->SetMapMode( MM_ANISOTROPIC );                                                                                                              /* pDC自定义坐标系 */
	pDC->SetWindowExt( rect.Width(), rect.Height() );                                                                                               /* 设置窗口范围 */
	pDC->SetViewportExt( rect.Width(), -rect.Height() );                                                                                            /* x轴水平向右，y轴垂直向上 */
	pDC->SetViewportOrg( rect.Width() / 2, rect.Height() / 2 );                                                                                     /* 屏幕中心为原点 */
	CDC	MemDC;                                                                                                                                  /* 内存DC */
	CBitmap NewBitmap, *pOldBitmap;                                                                                                                 /* 内存中承载图像的临时位图 */
	MemDC.CreateCompatibleDC( pDC );                                                                                                                /* 建立与屏幕pDC兼容的MemDC */
	NewBitmap.CreateCompatibleBitmap( pDC, rect.Width(), rect.Height() );                                                                           /* 创建兼容位图 */
	pOldBitmap = MemDC.SelectObject( &NewBitmap );                                                                                                  /* 将兼容位图选入MemDC */
	MemDC.SetMapMode( MM_ANISOTROPIC );                                                                                                             /* MemDC自定义坐标系 */
	MemDC.SetWindowExt( rect.Width(), rect.Height() );
	MemDC.SetViewportExt( rect.Width(), -rect.Height() );
	MemDC.SetViewportOrg( rect.Width() / 2, rect.Height() / 2 );
	ReadPoint();                                                                                                                                    /* 计算图形顶点坐标 */
	tran.Translate( translateX, translateY );                                                                                                       /* 平移变换 */
	tran.Rotate( rotate, CP2( translateX, translateY ) );                                                                                           /* 相对于任意点的旋转变换 */
	tran.Scale( scale, scale, CP2( translateX, translateY ) );                                                                                      /* 相对于任意点的比例变换 */
	DrawObject( &MemDC );
	BorderCheck();
	pDC->BitBlt( -rect.Width() / 2, -rect.Height() / 2, rect.Width(), rect.Height(), &MemDC, -rect.Width() / 2, -rect.Height() / 2, SRCCOPY );      /* 将内存位图拷贝到屏幕 */
	MemDC.SelectObject( pOldBitmap );                                                                                                               /* 恢复位图 */
	NewBitmap.DeleteObject();                                                                                                                       /*删除位图 */
	MemDC.DeleteDC();                                                                                                                               /*删除MemDC */
	ReleaseDC( pDC );                                                                                                                               /* 释放DC */
	if ( P != NULL )
	{
		delete[]P;
		P = NULL;
	}
}
```

**3.绘制图形**

在`CTransformPrgView`类中增加成员函数：`void DrawObject(CDC *pDC)`，并增加代码：

```
void CTransformPrgView::DrawObject( CDC *pDC )
{
	CLine *line = new CLine;
	for ( int i = 0; i < degree; i++ )
	{
		line->MoveTo( pDC, ROUND( P[degree].x ), ROUND( P[degree].y ) );
		line->LineTo( pDC, ROUND( P[i].x ), ROUND( P[i].y ) );
		line->LineTo( pDC, ROUND( P[(i + 1) % degree].x ), ROUND( P[(i + 1) % degree].y ) );
	}
	delete line;
}
```

在工程文件中导入`line.cpp`，`line.h`

**4.碰撞检测**

```
void CTransformPrgView::BorderCheck()
{
	double	TempR = R * scale;
	CRect	rect;                                                                           /* 定义客户区 */
	GetClientRect( &rect );                                                                 /* 获得客户区的大小 */
	int	nWidth	= rect.Width() / 2;
	int	nHeight = rect.Height() / 2;
	if ( fabs( P[degree].x ) + TempR > nWidth )
	{
		directionX	*= -1;
		translateX	+= fabs( fabs( P[degree].x ) + TempR - nWidth ) * directionX;   /* 判断球体水平越界 */
	}
	if ( fabs( P[degree].y ) + TempR > nHeight )
	{
		directionY	*= -1;
		translateY	+= fabs( fabs( P[degree].y ) + TempR - nHeight ) * directionY;  /* 判断球体垂直越界 */
	}
}
```

**5.定时器函数**

为`CTransformPrgView`类建立`WM_TIMER`映射函数，并增加代码：

```
void CTransformPrgView::OnTimer( UINT nIDEvent )
{
	/* TODO: Add your message handler code here and/or call default */
	CTransformPrgDoc* pDoc = GetDocument();
	if ( ( (CMainFrame *) AfxGetMainWnd() )->IsPlay )
	{
		degree		= pDoc->m_degree;
		translateX	+= pDoc->m_translateX * directionX;
		translateY	+= pDoc->m_translateY * directionY;
		rotate		+= pDoc->m_rotate;
		scale		= pDoc->m_scale;
		DoubleBuffer();
	}
	CView::OnTimer( nIDEvent );
}
```

在`CTransformPrgView`类的`OnDraw()`函数中增加代码：

```
void CTransformPrgView::OnDraw( CDC* pDC )
{
	CTransformPrgDoc* pDoc = GetDocument();
	ASSERT_VALID( pDoc );
	/* TODO: add draw code for native data here */
	SetTimer( 1, 50, NULL ); /* 设置定时器 */
}
```

**6.禁止背景刷新函数**

为`CTransformPrgView`类建立`WM_ERASEBRGND`映射函数，并增加代码：

```
BOOL CTransformPrgView::OnEraseBkgnd( CDC* pDC )
{
	/* TODO: Add your message handler code here and/or call default */

	return(TRUE);
}
```

**7.  `TransformPrgView.CPP`中增加以下头文件**

```
#include "Line.h"//直线类
#include "Mainfrm.h"//主框架头文件
#define ROUND(a) int(a+0.5)//四舍五入
#include "math.h"//数学头文件
#define  PI 3.14159265//圆周率
```

**8.  在`TransformPrgView.h`中定义以下变量：**

```
protected:
	CP2    *P;//变换点
	int	   directionX,directionY;//位移方向
	double translateX,translateY,rotate;
	double scale;
	int    degree;
	double R;//图形半径
	CTransForm tran;//变换对象
```

在TransformPrgView.h中增加以下头文件`#include "TransForm.h"`

在构造函数中初始化它们的值

```
CTransformPrgView::CTransformPrgView()
{
	/* TODO: add construction code here */
	degree		= 0;
	translateX	= 0;
	translateY	= 0;
	rotate		= 0;
	directionX	= 1;
	directionY	= 1;
	scale		= 0;
	R		= 100;
}
```

在CMainFrame类中定义变量`BOOL IsPlay;//动画控制**`

并在构造函数中设置其初始值为：`IsPlay=TRUE;`
