// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bresenham.h"
#include "Line.h"
#include "math.h"
#define Round(d) int(floor(d+0.5))//四舍五入宏定义


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{

}

CLine::~CLine()
{

}

void CLine::MoveTo(CDC *pDC,CP2 p0)
{
	start=p0;
}

void CLine::MoveTo(CDC *pDC,double x0,double y0)
{
	start=CP2(x0,y0);
}

void CLine::LineTo(CDC *pDC,CP2 p1)
{
  //此处编写代码绘制任意象限线段
   end=p1;
   CP2 p,t;
   double k,d;//斜率,d值
   CRGB clr=CRGB(0,0,0);
   double r,g,b;
   k=(end.y-start.y)/(end.x-start.x);//计算斜率
   double dc=1/(double)(end.x-start.x);
   //绘制斜率0<=k<=1的线段
	   if (0<=k && k<=1)   
	   {
		   if (start.x>end.x)   //判断绘制的是正向线段还是反向线段。起点在终点的左侧,绘制的是正向线段
		   {//反向线段则交换起点终点
			   t=start;start=end;end=t;
		   }
		   d=0.5-k;
		   for (p=start;p.x<end.x;p.x++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //设置线段颜色
			   pDC->SetPixelV(Round(p.x),Round(p.y),RGB(r*255,g*255,b*255));
			   if (d<0)
			   {
				   p.y++;
				   d+=1-k;
			   }
			   else
				   d-=k;
		   }
	   }
	   //绘制斜率k>1的线段
	   if(k>1)
	   {
			if (start.x>end.x)   //判断绘制的是正向线段还是反向线段。起点在终点的左侧,绘制的是正向线段
		   {//反向线段则交换起点终点
			   t=start;start=end;end=t;
		   }
			d = 1-0.5*k;
			for (p=start;p.y<end.y;p.y++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //设置线段颜色
			   pDC->SetPixelV(Round(p.x),Round(p.y),RGB(r*255,g*255,b*255));
			   if (d>=0)
			   {
				   p.x++;
				   d+=1-k;
			   }
			   else
				   d+=1;
		   }
	   }
	   //绘制斜率k<-1的线段
	   if(k<-1)
	   {
			if (start.x>end.x)   //判断绘制的是正向线段还是反向线段。起点在终点的左侧,绘制的是正向线段
		   {//反向线段则交换起点终点
			   t=start;start=end;end=t;
		   }
			d = -1-0.5*k;
			for (p=start;p.y>end.y;p.y--)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //设置线段颜色
			   pDC->SetPixelV(Round(p.x),Round(p.y),RGB(r*255,g*255,b*255));
			   if (d<0)
			   {
				   p.x++;
				   d=d-1-k;
			   }
			   else
				   d=d-1;
		   }
	   }
	   //绘制斜率-1<=k<0的线段
	   if(-1<=k && k<0)
	   {
			if (start.x>end.x)   //判断绘制的是正向线段还是反向线段。起点在终点的左侧,绘制的是正向线段
		   {//反向线段则交换起点终点
			   t=start;start=end;end=t;
		   }
			d = -0.5-k;
			for (p=start;p.x<end.x;p.x++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //设置线段颜色
			   pDC->SetPixelV(Round(p.x),Round(p.y),RGB(r*255,g*255,b*255));
			   if (d>0)
			   {
				   p.y=p.y-1;
				   d=d-1-k;
			   }
			   else
				   d=d-k;
		   }
	   }
   }


void CLine::LineTo(CDC *pDC,double x1,double y1)
{
   LineTo(pDC,CP2(x1,y1));
}