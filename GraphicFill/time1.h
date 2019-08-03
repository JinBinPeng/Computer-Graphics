#include<time.h>
#include<iostream.h>
class watch
{public:
	watch()
	{start=clock();
	 //   cout<<"正在计时……"<<endl;
	}
	~watch();
private:
	clock_t start;};

watch::~watch()
{  clock_t total=clock()-start;
		CString currentPos;
	currentPos.Format("耗时:%f",(double)(total) / CLOCKS_PER_SEC);
    AfxMessageBox(currentPos,MB_ICONQUESTION);
}
