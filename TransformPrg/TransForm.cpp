// TransForm.cpp: implementation of the CTransForm class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "transformPrg.h"
#include "TransForm.h"
#include "math.h"
#define PI 3.14159
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTransForm::CTransForm()
{

}

CTransForm::~CTransForm()
{

}

void CTransForm::SetMat(CP2 *p,int n)
{
	POld=p;
	num=n;
}

void CTransForm::Identity()//��λ����
{
	T[0][0]=1.0;T[0][1]=0.0;T[0][2]=0.0;
	T[1][0]=0.0;T[1][1]=1.0;T[1][2]=0.0;
	T[2][0]=0.0;T[2][1]=0.0;T[2][2]=1.0;
}

void CTransForm::Translate(double tx,double ty)//ƽ�Ʊ任����
{
	Identity();
	T[2][0]=tx; 
	T[2][1]=ty; 
	MultiMatrix();	
}

void CTransForm::Scale(double sx,double sy)//�����任����
{
	Identity();
	T[0][0]=sx; 
	T[1][1]=sy; 
	MultiMatrix();	
}

void CTransForm::Scale(double sx,double sy,CP2 p)//�������������������任����
{
	this->Translate(-p.x,-p.y);
	this->Scale(sx,sy);
	this->Translate(p.x,p.y);	
}

void CTransForm::Rotate(double beta)//��ת�任����
{
	Identity();
	double rad=beta*PI/180;
	T[0][0]=cos(rad); T[0][1]=sin(rad);
	T[1][0]=-sin(rad);T[1][1]=cos(rad);
	MultiMatrix();	
}

void CTransForm::Rotate(double beta,CP2 p)//�������������ת�任����
{
	this->Translate(-p.x,-p.y);
	this->Rotate(beta);
	this->Translate(p.x,p.y);	
}

void CTransForm::ReflectO()//ԭ�㷴��任����
{
	Identity();
	T[0][0]=-1;
	T[1][1]=-1;
	MultiMatrix();	
}

void CTransForm::ReflectX()//X�ᷴ��任����
{
	Identity();
	T[0][0]=1;
	T[1][1]=-1;
	MultiMatrix();	
}

void CTransForm::ReflectY()//Y�ᷴ��任����
{
	Identity();
	T[0][0]=-1;
	T[1][1]=1;
	MultiMatrix();	
}

void CTransForm::Shear(double b,double c)//���б任����
{
	Identity();
	T[0][1]=b;
	T[1][0]=c;
	MultiMatrix();	
}

void CTransForm::MultiMatrix()//�������
{
	CP2 *PNew=new CP2[num];	
	for(int i=0;i<num;i++)
	{
		PNew[i]=POld[i];
	}
	for(int j=0;j<num;j++)
	{
		POld[j].x=PNew[j].x*T[0][0]+PNew[j].y*T[1][0]+PNew[j].w*T[2][0];
		POld[j].y=PNew[j].x*T[0][1]+PNew[j].y*T[1][1]+PNew[j].w*T[2][1];
		POld[j].w=PNew[j].x*T[0][2]+PNew[j].y*T[1][2]+PNew[j].w*T[2][2];
	}
	delete []PNew;
}
