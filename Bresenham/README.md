####[实验目的]

**1、掌握任意斜率的直线段中点Bresenham扫描转换算法**

**2、掌握Cline直线段类的设计方法**

####[实验要求]

1、设计CLine直线类，其数据成员为直线段的起点坐标start和终点坐标end，成员函数为MoveTo()和LineTo()函数。

2、CLine直线类的LineTo函数使用中点Bresenham算法绘制任意斜率k的直线段，包括水平、垂直、k>1、0≤k≤1、-1≤k<0，k<-1的情况。

3、自定义屏幕二维坐标系，原点位于客户区中心，x轴水平向右为正，y轴垂直向上为正。

4、在屏幕客户区按下鼠标左键，选择直线的起点，保持鼠标左键按下并移动鼠标到另一个位置，弹起鼠标左键绘制任意斜率的直线段

5、状态栏动态显示鼠标移动时鼠标的位置

####[实验准备]

1、打开工程Bresenham，工程中已包括自定义类:

CP2:点类

CRGB:颜色类

CLine:直线类

2、请阅读CLine直线类函数`LineTo(CDC *pDC,CP2 p1)`的代码,此函数采用Bresenham算法绘制斜率k在[0,1]区间的线段

3、请阅读`BresenhamView.cpp`中的`onDraw`函数代码，此函数调用CLine类的MoveTo、LineTo 函数绘制一条线段。

####[实验内容]

1、改写CLine直线类函数`LineTo(CDC *pDC,CP2 p1)`的代码，实现绘制任意斜率的直线，包括垂直和水平线。

2、改写`BresenhamView.cpp`中的onDraw函数代码，使用CLine类的MoveTo、LineTo 函数绘制经过原点（0，0）的6条线段（包括水平、垂直、k>1、0≤k≤1、-1≤k<0，k<-1，几种情况，坐标自定）如下图所示：

![image.png](https://upload-images.jianshu.io/upload_images/4630295-da509a79667c81a1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


**[相关内容]**

**Bresenham算法绘制任意象限直线，递推公式，见图**

![image.png](https://upload-images.jianshu.io/upload_images/4630295-9949d9d1b8c7c0ee.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

