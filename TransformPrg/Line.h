// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__C6B26576_7811_4023_9F91_BB190BEA076D__INCLUDED_)
#define AFX_LINE_H__C6B26576_7811_4023_9F91_BB190BEA076D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *,CPoint);//移动到指定位置
	void MoveTo(CDC *,long,long);
	void LineTo(CDC *,CPoint);//绘制直线，不含终点
	void LineTo(CDC *,long,long);
public:
	CPoint P0;//起点
	CPoint P1;//终点
};

#endif // !defined(AFX_LINE_H__C6B26576_7811_4023_9F91_BB190BEA076D__INCLUDED_)
