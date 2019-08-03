// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Bresenham.h"
#include "Line.h"
#include "math.h"
#define Round(d) int(floor(d+0.5))//��������궨��


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
  //�˴���д����������������߶�
   end=p1;
   CP2 p,t;
   double k,d;//б��,dֵ
   CRGB clr=CRGB(0,0,0);
   double r,g,b;
   k=(end.y-start.y)/(end.x-start.x);//����б��
   double dc=1/(double)(end.x-start.x);
   //����б��0<=k<=1���߶�
	   if (0<=k && k<=1)   
	   {
		   if (start.x>end.x)   //�жϻ��Ƶ��������߶λ��Ƿ����߶Ρ�������յ�����,���Ƶ��������߶�
		   {//�����߶��򽻻�����յ�
			   t=start;start=end;end=t;
		   }
		   d=0.5-k;
		   for (p=start;p.x<end.x;p.x++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //�����߶���ɫ
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
	   //����б��k>1���߶�
	   if(k>1)
	   {
			if (start.x>end.x)   //�жϻ��Ƶ��������߶λ��Ƿ����߶Ρ�������յ�����,���Ƶ��������߶�
		   {//�����߶��򽻻�����յ�
			   t=start;start=end;end=t;
		   }
			d = 1-0.5*k;
			for (p=start;p.y<end.y;p.y++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //�����߶���ɫ
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
	   //����б��k<-1���߶�
	   if(k<-1)
	   {
			if (start.x>end.x)   //�жϻ��Ƶ��������߶λ��Ƿ����߶Ρ�������յ�����,���Ƶ��������߶�
		   {//�����߶��򽻻�����յ�
			   t=start;start=end;end=t;
		   }
			d = -1-0.5*k;
			for (p=start;p.y>end.y;p.y--)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //�����߶���ɫ
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
	   //����б��-1<=k<0���߶�
	   if(-1<=k && k<0)
	   {
			if (start.x>end.x)   //�жϻ��Ƶ��������߶λ��Ƿ����߶Ρ�������յ�����,���Ƶ��������߶�
		   {//�����߶��򽻻�����յ�
			   t=start;start=end;end=t;
		   }
			d = -0.5-k;
			for (p=start;p.x<end.x;p.x++)
		   {
			   r=(1-(end.x-start.x)*dc),g=0,b=1-(p.x-start.x)*dc; //�����߶���ɫ
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