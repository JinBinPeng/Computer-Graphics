#### 实验目的：

1、koch曲线的定义

2、生成元递归算法

#### 实验说明：

给定不同的递归深度，绘制koch曲线。

#### 功能描述：

1、自定义屏幕二维坐标系，原点位于客户去中心，x轴水平向右为正，y垂直向上为正。

2、使用对话框输入koch曲线的递归深度和夹角，绘制koch曲线。

#### 算法分析：

1、koch曲线是著名的分形曲线，具有自相似性，其生成元如图所示。生成元的第一段直线和第二段直线之间的夹角可以为任意角度θ（0<θ<90）。最常用的角度是60和85度。生成元的起点和终点坐标分别为P0和P1，koch生成元有4段直线构成。Koch曲线的递归调用就是通过反复使用生成元来取代每一条直线而实现的。

![image.png](https://upload-images.jianshu.io/upload_images/4630295-b84fd13719ecefcd.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

已知初始直线段的起点和终点，可以计算出长度L0

![image.png](https://upload-images.jianshu.io/upload_images/4630295-5ba0af6e885af06a.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

设递归n次后最小线元的长度为d,则

![image.png](https://upload-images.jianshu.io/upload_images/4630295-15cfa0bdb1b077a1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

生成元按照以下步骤绘制：

**1.从起点`P0`出发，取直线段和水平轴的夹角`α=0`,根据最小线元长度d绘制`P0Pi`直线段。**

**2.改变`α=α+θ`，根据最小线元长度d绘制`PiPj`直线段**

**3.改变`α=α-2θ`，根据最小线元长度d绘制`PjPk`直线段**

**4.改变`α=α+θ`，根据最小线元长度d绘制`PjP1`直线段**

**四、算法设计：**

1、输入递归深度n和夹角θ。

2、取初始水平直线段的高度为距离客户区下边界100像素处，起点水平坐标取自客户区左侧，终点水平坐标取自客户区右侧。

3、根据初始直线段的起始坐标P0和终点坐标P1，计算

![image.png](https://upload-images.jianshu.io/upload_images/4630295-ecee94cb48ece61c.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

4、计算递归n次后，最小线元的长度

![image.png](https://upload-images.jianshu.io/upload_images/4630295-485711ad098d2ec7.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

5、先绘制第一段直线，然后改变夹角α，分别绘制其余三段直线。注意各段之间夹角的改变。

绘制第一段`α=0`，绘制第二段`α=α+θ`，绘制第三段`α=α-2θ`，绘制第四段`α=α+θ`

6、执行递归子程序，对生成元的各部分进行递归

#### 实验步骤：

**1.设计对话框，接收递归深度n和夹角θ。**

设计对话框界面

在工程资源窗口的`Resource View`面板中，选择`Dialog`并右击，选择`Insert Dialog`，编辑对话框资源，如下图所示：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-71b4ea46254bb688.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

 为对话框增加2个`StaticText`控件和2个`Edit box`控件。如图所示。`Edit box`标识符从上至下依次为`IDC_EDIT1~IDC_EDIT2`。

创建对话框类

双击对话框，选择创建对话框类。

![image.png](https://upload-images.jianshu.io/upload_images/4630295-a8900db337d702f1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

![image.png](https://upload-images.jianshu.io/upload_images/4630295-37d8851e4066eafc.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

对话框控件的消息映射

选择`View|Class Wizard`，打开`MFC ClassWizard`对话框，切换到`Message Variables`，为对话框添加数据成员的名称和类型。选择`IDC_EDIT1`，单击`Add Variables`，添加值变量`m_n`，限制其最小值为0，最大值为10。

![image.png](https://upload-images.jianshu.io/upload_images/4630295-f48c89038fc4c841.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

选择`IDC_EDIT2`，单击`Add Variables`，添加值变量`m_a`，限制其最小值为0，最大值为89。

4）设置编辑框控件的初始值。

修改`CInputDlg`类的构造函数：

```
CInputDlg::CInputDlg( CWnd* pParent /*=NULL*/ )
	: CDialog( CInputDlg::IDD, pParent )
{
	/* {{AFX_DATA_INIT(CInputDlg) */
	m_n	= 5;
	m_a	= 60;
	/* }}AFX_DATA_INIT */
}
```

**2、设计菜单资源**

在`ResourceView`上双击`Menu`，打开`IDR_MAINFRAME`，修改菜单项内容，如下图所示：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-df5d2b01b18ff278.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

添加子菜单项的消息映射函数

选择菜单中的“查看|建立类向导”，打开`MFC ClassWizard`对话框，切换到`Message Maps`选项卡，注意`class name`、`object IDs`、`Messages`的设置，单击`Add Function`按钮添加函数，参考下图：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-4115cfe42a163472.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

确定后，可以在`CKochView`中找到`onKoch`函数。

**3.为CKochView类增加保护成员变量：**

```
CDC	*pDC;           /* 设备上下文对象 */
int	n;              /* 递归深度 */
CP2	P0, P1;         /* 直线的起点和终点 */
double	Theta;          /* koch夹角 */
double	L0, Alpha, d;   /* 初始线段的长度和起始角度,等分线段的长度 */
```

注意需添加头文件：
`#include "InputDlg.h"`//对话框
 `#include "P2.h"`

**4. 为CKochView类增加公有成员函数（KochView.h）**

`void Koch(int n);//koch函数`

**5.为KochView.cpp增加相应的头文件：**

```
#define PI 3.1415926                            /* PI的宏定义 */
#include "math.h"                               /* 数学头文件 */
#define Round( d ) int(floor( d + 0.5 ) )       /* 四舍五入宏定义 */
```

**6.在CKochView类构造函数中初始化变量：**

`pDC=NULL;   `

**7.修改CKochView类OnKoch函数的代码：**

```
void CKochView::OnKoch()
{
	/* TODO: Add your command handler code here */
	CInputDlg dlg;
	if ( IDOK == dlg.DoModal() )
	{
		n	= dlg.m_n;
		Theta	= dlg.m_a;
	}else
		return;
	RedrawWindow();
	pDC = GetDC();
	CRect rect; /* 客户区矩形对象 */
	GetClientRect( &rect );
	pDC->SetMapMode( MM_ANISOTROPIC );
	pDC->SetWindowExt( rect.Width(), rect.Height() );
	pDC->SetViewportExt( rect.Width(), -rect.Height() );
	pDC->SetViewportOrg( rect.Width() / 2, rect.Height() / 2 );
	rect.OffsetRect( -rect.Width() / 2, -rect.Height() / 2 );
	P0.x	= -rect.Width() / 2.0, P0.y = -rect.Height() / 2.0 + 100;
	P1.x	= rect.Width() / 2.0, P1.y = -rect.Height() / 2.0 + 100;
	Alpha	= atan( (P1.y - P0.y) / (P1.x - P0.x) );
	L0	= sqrt( (P1.x - P0.x) * (P1.x - P0.x) + (P1.y - P0.y) * (P1.y - P0.y) );
	Theta	= Theta * PI / 180;
	d	= L0 / pow( 2 * (1 + cos( Theta ) ), n );
	Koch( n );
	ReleaseDC( pDC );
}
```

**8. 实现Koch代码，绘制Koch曲线**

```
void CKochView::Koch( int n )
{
	if ( 0 == n )
	{
		P1.x	= P0.x + d	*cos( Alpha );
		P1.y	= P0.y + d	*sin( Alpha );
		pDC->MoveTo( Round( P0.x ), Round( P0.y ) );
		pDC->LineTo( Round( P1.x ), Round( P1.y ) );
		P0 = P1;
		return;
	}
	Koch( n - 1 );
	Alpha += Theta;
	Koch( n - 1 );
	Alpha -= 2 * Theta;
	Koch( n - 1 );
	Alpha += Theta;
	Koch( n - 1 );
}
```