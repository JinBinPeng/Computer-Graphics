#include "stdafx.h"



void CPointList::AddTail(CPoint p)
{
	CPointList *temp;
	temp=new CPointList;
	temp->point.x=p.x;
	temp->point.y=p.y;
	temp->next=NULL;
	if (tail) tail->next=temp;
	tail=temp;
	if (!head) head=tail;
	count++;
}

CPoint *CPointList::Getnode(int i)
{	if (i<=count) 
	{	CPointList *temp;
	  CPointList *p=head;
	   if (!head)
	     {	  return 0;	}
	while (i-1!=0) {p=p->next;i--;}
	temp=p;
	return &temp->point;}
	else 
	{	return 0;}
}
void CPointList::clear()
{
 CPointList *p=head;
 CPointList *q;
 q=p;
 while (p!=NULL)
 {
	 q=p->next;
	 if (q==NULL)
	 {
		 head=tail=NULL;
		 
	 }
	 else delete (p);	 
	 count--;
	 p=q;
 }
}