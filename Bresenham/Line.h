// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__753D506B_810E_4ABB_98C0_292B38F944B4__INCLUDED_)
#define AFX_LINE_H__753D506B_810E_4ABB_98C0_292B38F944B4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "P2.h"
#include "rgb.h"

class CLine  
{
public:
	CLine();
	virtual ~CLine();
	void MoveTo(CDC *,CP2);
	void MoveTo(CDC *,double,double);
	void LineTo(CDC *,CP2);
	void LineTo(CDC *,double,double);
public:
	CP2 start;
	CP2 end;
};

#endif // !defined(AFX_LINE_H__753D506B_810E_4ABB_98C0_292B38F944B4__INCLUDED_)
