#### 实验目的：

1、了解Bezier曲线方程，
2、理解Bezier曲线的`DeCasteljau`递归算法
3、掌握控制多边形的绘制方法、阶乘函数编程方法、二维数组动态创建方法

#### 实验说明：

使用鼠标左键在屏幕客户区绘制控制点，在菜单中选择Bezier曲线方程，或者DeCasteljau递归算法，实现绘制n次Bezier曲线。

#### 功能描述：
1、根据Bezier曲线方程或者`DeCasteljau`递归算法绘制n次Bezier曲线
2、使用鼠标左键绘制任意的控制点，直线段连接成为控制多边形。控制点最大值限制为21，可以绘制的Bezier曲线最大阶次数为20.
3、通过菜单选择绘制曲线的方法。
4、使用黑色线段绘制控制多边形，使用半径为2的灰色实心圆绘制控制点，使用蓝色直线段连接控制点绘制曲线

#### 算法设计：

1、在屏幕上使用鼠标左键指定控制点，将控制点坐标存储在数组P中
2、读入的顶点个数为`CtrlPointNum`，Bezier曲线的阶次`n=CtrlPointNum-1`
3、将i从0循环到n，依次使用直线段连接`p[i]`与`p[i+1]`，以每个控制点坐标为圆心，绘制半径为2个像素的圆。
4、选择菜单：Bezier曲线方程，调用`DrawnBezier`函数，根据Bezier曲线方程绘制曲线
5、选择菜单：`DeCasteljau`递归算法，调用`DrawDeCasteljau`函数，利用递推算法绘制曲线。