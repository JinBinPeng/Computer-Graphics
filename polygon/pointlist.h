class CPointList
{	CPoint point;
	CPointList *next; CPointList *head,*tail;
	int count;
public:
	CPointList()
	{ 
		head=next=tail=NULL;count=0;
	}
	int GetSize() { return count;}
	void AddTail(CPoint p);
	CPoint *Getnode(int i);
	void clear();
};
