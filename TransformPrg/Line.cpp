// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransformPrg.h"
#include "Line.h"

#include "math.h"
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

void CLine::MoveTo(CDC *pDC,CPoint p0)
{	
	P0=p0;
}

void CLine::MoveTo(CDC *pDC,long x0,long y0)
{	
	P0.x=x0,P0.y=y0;
}
void CLine::LineTo(CDC *pDC,CPoint p1)
{
	P1=p1;
	CPoint p,t;
	COLORREF crColor=RGB(255,255,255);//白色像素点
	if(abs(P0.x-P1.x)<0)//绘制垂线
	{
		if(P0.y>P1.y)//交换顶点,使得起始点低于终点顶点
		{
			t=P0;P0=P1;P1=t;
		}
		for(p=P0;p.y<P1.y;p.y++)
		{
			pDC->SetPixel(p,crColor);	
		}
	}
	else
	{
		double k,d;
		k=(double)(P1.y-P0.y)/(double)(P1.x-P0.x);
		if(k>1.0)//绘制k>1
		{
			if(P0.y>P1.y)
			{
				t=P0;P0=P1;P1=t;
			}
			d=1-0.5*k;
			for(p=P0;p.y<P1.y;p.y++)
			{
				pDC->SetPixel(p,crColor);
                if(d>=0)
				{
					p.x++;
					d+=1-k;
				}
				else 
                    d+=1;       
			}
		}
		if(0.0<=k && k<=1.0)//绘制0<=k<=1
		{
			if(P0.x>P1.x)
			{
				t=P0;P0=P1;P1=t;
			}
			d=0.5-k; 
			for(p=P0;p.x<P1.x;p.x++)
			{
				pDC->SetPixel(p,crColor);
                if(d<0)
				{
					p.y++;
					d+=1-k;
				}
				else 
					d-=k;		
			}
		}		
		if(k>=-1.0 && k<0.0)//绘制-1<=k<0
		{
			if(P0.x>P1.x)
			{
				t=P0;P0=P1;P1=t;
			}
			d=-0.5-k;
            for(p=P0;p.x<P1.x;p.x++)
			{
				pDC->SetPixel(p,crColor);
                if(d>0)
				{
					p.y--;
					d-=1+k;
				}
				else 
					d-=k;		
			}
		}
		if(k<-1.0)//绘制k<-1 
		{
			if(P0.y<P1.y)
			{
				t=P0;P0=P1;P1=t;
			}
			d=-1-0.5*k;
			for(p=P0;p.y>P1.y;p.y--)
			{
				pDC->SetPixel(p,crColor);
                if(d<0)
				{
					p.x++;
					d-=1+k;
				}
				else 
					d-=1;           
			}
		}
	}
	P0=p1;
}
void CLine::LineTo(CDC *pDC,long x1,long y1)//重载函数
{
	LineTo(pDC,CPoint(x1,y1));
}

