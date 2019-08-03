#### 实验目的：

1、了解OpenGL编程环境

2、在VC++中设置OpenGL编程环境

3、使用OpenGL实现三维变换以及真实感图形绘制

#### 实验步骤：

**1.OpenGL环境设置**

在`stdafx.h`中添加语句：
```
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glaux.h>
#include <gl\glut.h>
```

2.选择菜单[工程|设置],在Link标签页中，对象/库模块设置中，输入：`OpenGL32.lib GLu32.lib glaux.lib glut32.lib`

3.将glut.h头文件复制到vc安装目录下的`include/gl`目录下，同时将`glut.lib`  `glut32.lib`复制到`vc`安装目录下的`lib`文件夹中，并将`glut32.dll`,`glut.dll`复制到`window`系统目录的`system32`文件夹中

4.以上设置做好后，请运行程序，看是否能正常执行。

 **2.VC++中，对opengl绘图环境的初始化,请参阅openview.cpp中下列函数的代码**
```
PreCreateWindow
SetWindowPixelFormat
CreateViewGLContext
OnCreate
```
**3.三维几何变换的实现**

平移变换，请运行程序，并设置`tx`,`ty`,`tz`的值，观察图形的变换。系统已经定义了`tx`,`ty`,`tz`用于接收用户输入的值。

请参阅`movecube`的代码，并在每条语句后面加上注释，解释语句的作用。

```
glMatrixMode( GL_PROJECTION );                                          /* 设置模型变换，指定当前操作的矩阵为投影矩阵 */
glLoadIdentity();                                                       /*复原矩阵为单位矩阵 */
double winHt = 1.0;
glOrtho( -winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1, 100 );  /* 创建正交投影 */
glMatrixMode( GL_MODELVIEW );                                           /* 指定当前操作的矩阵为模型视图矩阵 */
glLoadIdentity();                                                       /*复原矩阵为单位矩阵 */
gluLookAt( 2, 2, 2, 0, 0, 0, 0.0, 1, 0 );                               /* 设置相机的位置和方向 */
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );                   /* 清除颜色缓存区和深度缓存区 */
glPushMatrix();                                                         /* 入栈 */
glTranslated( tx, ty, tz );                                             /* 平移操作 */
glutWireTeapot( 0.5 );                                                  /* 画茶壶 */
glPopMatrix();                                                          /* 出栈 */
glFlush();                                                              /* 结束绘图 */
```

缩放变换。系统已经定义了sx,sy,sz用于接收用户输入的值,补充scaleCube函数中的代码，实现缩放变换。

```
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
double winHt = 1.0;
glOrtho( -winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1, 100 );
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
gluLookAt( 2, 2, 2, 0, 0, 0, 0.0, 1, 0 );
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
glPushMatrix();
glScaled( sx, sy, sz );
glutWireTeapot( 0.5 );
glPopMatrix();
glFlush();
```

旋转变换。系统已经定义了angle,rx,ry,rz用于接收用户输入的值,补充rotateCube函数中的代码，实现旋转变换。

```
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
double winHt = 1.0;
glOrtho( -winHt * 64 / 48, winHt * 64 / 48, -winHt, winHt, 0.1, 100 );
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
gluLookAt( 2, 2, 2, 0, 0, 0, 0.0, 1, 0 );
glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
glPushMatrix();
glRotated( angle, rx, ry, rz );
glutWireTeapot( 0.5 );
glPopMatrix();
glFlush();
```

绘制网格物体

参照下方的图片，在`displayWire()`函数中增加代码，绘制图形

![image.png](https://upload-images.jianshu.io/upload_images/4630295-1f6dbca624a37ed3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


`displayWird()`函数中原有的代码显示以下图形：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-7869b2b292bd8617.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


其中三个圆锥所在的线是x,y,z轴坐标。用到的图形显示函数包括：`glutWireCube`、`glutWireSphere`、`glutWireCone`、`glutWireTeapot`、`glutWireTorus`、`glutWireDodecahedron()`、`glutWireIcosahedron()`，查找函数的说明，结合`displayWire()`中的已有的代码实现图形绘制。

```
glMatrixMode( GL_PROJECTION );
glLoadIdentity();
glOrtho( -2 * aspect, 2 * aspect, -2, 2, 0.1, 100 );
glMatrixMode( GL_MODELVIEW );
glLoadIdentity();
gluLookAt( 2, 2, 2, 0, 0, 0, 0.0, 1, 0 );
glClear( GL_COLOR_BUFFER_BIT );

/*
 * axis(0.5);
 * glPushMatrix();
 * glRotated(90,0,1,0);
 * axis(0.5);
 * glRotated(90,1,0,0);
 * axis(0.5);
 * glPopMatrix();
 */

glPushMatrix();
glTranslated( 0.5, 0.5, 0.5 );
glutWireCube( 2 );
glPopMatrix();

glPushMatrix();
glutWireTeapot( 0.3 );
glPopMatrix();

glPushMatrix();
glTranslated( 2, 0, 2 );
glRotated( 45, 0, 0, 0 );
glutWireCone( 0.4, 1, 15, 15 );
glPopMatrix();

glPushMatrix();
glTranslated( 0, 2, 2 );
glutWireCube( 0.5 );
glPopMatrix();

glPushMatrix();
glTranslated( 2, 2, 0 );
glutWireSphere( 0.5, 10, 10 );
glPopMatrix();

glPushMatrix();
glTranslated( 0, 2, 0 );
glutWireTorus( 0.1, 0.4, 10, 10 );
glPopMatrix();

glPushMatrix();
glTranslated( 2, 0, 0 );
glScaled( 0.3, 0.3, 0.3 );
glutWireDodecahedron();
glPopMatrix();

glPushMatrix();
glTranslated( 0, 0, 2 );
glScaled( 0.4, 0.4, 0.4 );
glutWireIcosahedron();
glPopMatrix();

glFlush();
```
**4.光照和材质处理**

设置光源的代码

```
glEnable( GL_LIGHTING );
glEnable( GL_LIGHT0 );

GLfloat lightIntensity[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat light_position[] = { 2.0f, 6.0f, 3.0f, 0.0f };
glLightfv( GL_LIGHT0, GL_POSITION, light_position );
glLightfv( GL_LIGHT0, GL_DIFFUSE, lightIntensity );
```

如果要调整光源位置，应该修改下列语句

`GLfloat light_position[]={2.0f,6.0f,3.0f,0.0f};`

设置材质的代码

```
GLfloat mat_ambient[] = { 1.0f, 0.0f, 0.0f, 1.0f };
GLfloat mat_diffuse[] = { 0.7f, 0.7f, 0.7f, 1.0f };
GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
GLfloat mat_shininess[] = { 50.0f };

glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient );
glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse );
glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular );
glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess );
```

修改漫反射光、镜面反射光、环境光等参数，得到不同的图形显示，并截图贴在下方

##### 修改环境光

![image.png](https://upload-images.jianshu.io/upload_images/4630295-5f544b87574557a5.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

##### 修改漫反射光

![image.png](https://upload-images.jianshu.io/upload_images/4630295-3440bf680ffee84b.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

##### 修改镜面反射光

![image.png](https://upload-images.jianshu.io/upload_images/4630295-93c36e72dac30412.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

##### 修改光泽度

![image.png](https://upload-images.jianshu.io/upload_images/4630295-18c11017358e566f.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

