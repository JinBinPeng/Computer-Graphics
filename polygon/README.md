#### 实验目的：

1、掌握Sutherland-Hodgeman算法的基本原理

2、在VC++环境中实现相关算法

#### 实验内容

实验是裁剪指定的多边形：ABCDE

程序运行后在“多边形裁剪”中选择`Sutherland-Hodgeman`算法，即可查看裁剪结果。

编程主要用到的变量(无须自己定义)：

**CPoint类型的数组a，记录输入顶点信息，初值中记录了多边形ABCDE的5个顶点坐标。**

**CPoint类型的数组b，用于记录裁剪后输出的多边形的顶点坐标。**

**CRect类型的clipwin，记录裁剪窗口的边界信息。可以访问该变量的left,right, top,bottom 成员获得各边界信息**

**int类型的变量inlen ,outlen，用于记录输入以及输出的多边形顶点数。Inlen初始值为5。**

#### 在Cpolygonview类中完成以下各个函数的代码。

`void CPolygonView::SutherlandHodgmanClip(CPoint InVertexArray[], CPoint OutVertexArray[], CPoint ClipBoundary[], int Inlength, int &Outlength)`，

实现sh算法，
`InVertexArray`为输入顶点数组，
`OutVertexArray `为输出顶点数组，
`ClipBoundary` 为裁剪边，
`Inlength` 为输入顶点数，
`Outlength`为输出顶点个数。

算法需要调用函数`Inside`，`Intersect`完成点的位置判断和交点坐标计算，两个函数的声明请参考下方。

**`bool CPolygonView::Inside(CPoint TestPt, CPoint ClipBoundary[])`，测试点A在裁剪边的内侧还是外侧。**

**`void CPolygonView::Intersect(CPoint S, CPoint P, CPoint ClipBoundary[], CPoint &IntersectPt)`，求线段sp边的交点，返回交点坐标。**

**`CPolygonView` 的`OnDraw`函数中负责调用`SutherlandHodgmanClip`算法得到裁剪结果并绘制图形**