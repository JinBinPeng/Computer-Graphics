// RGB.h: interface for the CRGB class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RGB_H__8A554708_A6EC_4335_BCF2_285A47C2E1A4__INCLUDED_)
#define AFX_RGB_H__8A554708_A6EC_4335_BCF2_285A47C2E1A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRGB  
{
public:
	CRGB();
	CRGB(double,double,double);
	virtual ~CRGB();
	friend CRGB operator+ (const CRGB &,const CRGB &);
    friend CRGB operator- (const CRGB &,const CRGB &);
    friend CRGB operator* (const CRGB &,const CRGB &);
	friend CRGB operator* (const CRGB &,double);
	friend CRGB operator* (double,const CRGB &);
    friend CRGB operator/ (const CRGB &,double);
    friend CRGB operator+= (CRGB &,CRGB &);
	friend CRGB operator-= (CRGB &,CRGB &);
	friend CRGB operator*= (CRGB &,CRGB &);
	friend CRGB operator/= (CRGB &,double);
	void Normalize();
public:
	double red;
	double green;
	double blue;
};

#endif // !defined(AFX_RGB_H__8A554708_A6EC_4335_BCF2_285A47C2E1A4__INCLUDED_)
