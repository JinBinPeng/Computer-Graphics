#### 实验目的

**学习区域填充的递归算法、扫描线算法**

#### 实验内容

##### 递归实现的区域填充算法

**1、区域填充算法（边界表示）**

（1）在GraphicFillView.cpp文件中，实现函数boundaryFill4中的代码，注意需定义CClientDC类的对象（例如dc），并使用该对象调用`GetPixel(x,y)`函数获得当前点的颜色，调用`SetPixel(x,y,color)`函数设置当前点的颜色。

（2）运行程序浏览边界填充算法效果

1.先选择属性|填充颜色，设置填充色

2.选择图形填充算法|边界填充算法

3.鼠标在多边形内部任意位置单击，可以看到填充效果

```                                                                                        
	CClientDC dc(this);
	int color = dc.GetPixel(x,y);
	if(color != fill && color != boundary){
		dc.SetPixel(x,y,fill);
		boundaryFill4(x,y+1,fill,boundary);
		boundaryFill4(x,y-1,fill,boundary);
		boundaryFill4(x+1,y,fill,boundary);
		boundaryFill4(x-1,y,fill,boundary);
	}
```
**2、区域填充算法（内点表示）**

（1）在GraphicFillView.cpp文件中，实现函数`floodFill4`中的代码，注意需定义CClientDC类的对象（例如dc），并使用该对象调用`GetPixel(x,y)`函数获得当前点的颜色，调用`SetPixel(x,y,color)`函数设置当前点的颜色。

（2）运行程序浏览泛填充算法效果

1.先选择属性|填充颜色，设置填充色

2.选择图形填充算法|泛填充算法

3.鼠标在多边形内部任意位置单击，可以看到填充效果

```
    CClientDC dc(this);
	int color = dc.GetPixel(x,y);
	if(color == oldcolor){
		dc.SetPixel(x,y,newcolor);
		floodFill4(x,y+1,oldcolor,newcolor);
		floodFill4(x,y-1,oldcolor,newcolor);
		floodFill4(x+1,y,oldcolor,newcolor);
		floodFill4(x-1,y,oldcolor,newcolor);
	}
```

##### 非递归实现的区域填充算法

boundaryFill4中通过递归方式实现的代码，事实上只是易于理解基本填充原理，在实际中是不使用这种方法的。请在`boundaryFill4_stack`中将算法改为使用栈来实现。

```
CClientDC dc(this);
    stack <CPoint> ptStack;//用来保存需要填充的点 
	 CPoint ptCurrent = CPoint(x, y);    //将种子点设为当前需要填的点  
    ptStack.push( ptCurrent );          //将种子点压入堆栈中  
    while ( !ptStack.empty() )  
    {  		
        ptCurrent = ptStack.top(); 
		int color=dc.GetPixel(ptCurrent.x,ptCurrent.y);
		if(color!=fill&&color!=boundary)
        dc.SetPixel( ptCurrent.x,ptCurrent.y, fill ); // 填充该点  
        ptStack.pop();  // 出栈   
        CPoint ptArround[ 4 ];  
        ptArround[ 0 ] = CPoint( ptCurrent.x - 1, ptCurrent.y );  
        ptArround[ 1 ] = CPoint( ptCurrent.x + 1, ptCurrent.y );  
        ptArround[ 2 ] = CPoint( ptCurrent.x, ptCurrent.y - 1 );  
        ptArround[ 3 ] = CPoint( ptCurrent.x, ptCurrent.y + 1 );            
        // 将当前点点周围四个点压入栈中  
        for ( int i = 0; i < 4; i ++ )  
        {  
            if( dc.GetPixel( ptArround[ i ] ) != fill )  
            {  
            ptStack.push( ptArround[i] );  // 入栈  
            }  
        }
```

##### 扫描线区域填充算法

在`GraphicFillView.cpp`文件中，实现ScanLineFill4中的代码，必须定义栈类来存储种子点，栈类中必须包括 `setstackempty`、`isstackempty`、`stackpush`、`stackpop`** 等成员函数。

```
//函数参数说明：x,y为种子点坐标，oldcolor为区域的原色，newcolor为填充色
Span span;
span.y	= y;
span.xl = x;
CClientDC dc( this );
while ( dc.GetPixel( span.xl, span.y ) == oldcolor )
{
	dc.SetPixel( span.xl, span.y, newcolor );
	span.xl--;
}
if ( span.xl == x )     /* not a seed point actually */
	return;
else
	span.xl++;      /* compansate */
span.xr = x + 1;
while ( dc.GetPixel( span.xr, span.y ) == oldcolor )
{
	dc.SetPixel( span.xr, span.y, newcolor );
	span.xr++;
}
if ( span.xr == x + 1 ) /* cannot extend to right */
	span.xr = x;
else
	span.xr--;      /* compansate */

SetStackEmpty();
PushStack( &span );

while ( !isStackEmpty() )
{
	PopStack( &span );
	Span S; /* new span */
	{
		S.y	= span.y + 1;
		S.xl	= span.xl;
		bool xLeftNotSet = false;
		while ( dc.GetPixel( S.xl, S.y ) == oldcolor )
		{
			S.xl--;
		}
		if ( S.xl == span.xl )  /* xLeft is not set */
			xLeftNotSet = true;
		else
			S.xl++;         /* compansate */
		int i = S.xl;
		while ( i <= span.xr )
		{
			while ( dc.GetPixel( i, S.y ) == oldcolor )
			{
				if ( xLeftNotSet )
				{
					S.xl		= i;
					xLeftNotSet	= false;
				}
				dc.SetPixel( i, S.y, newcolor );
				i++;
			}
			if ( i > S.xl )
			{
				S.xr = i - 1;
				PushStack( &S );
				xLeftNotSet = true;
			}
			while ( i <= span.xr && dc.GetPixel( i, S.y ) != oldcolor )
			{
				i++;
			}
		}
	}
	{       /* similar to above */
		S.y	= span.y - 1;
		S.xl	= span.xl;
		bool xLeftNotSet = false;
		while ( dc.GetPixel( S.xl, S.y ) == oldcolor )
		{
			S.xl--;
		}
		if ( S.xl == span.xl )  /* xLeft is not set */
			xLeftNotSet = true;
		else
			S.xl++;         /* compansate */
		int i = S.xl;
		while ( i <= span.xr )
		{
			while ( dc.GetPixel( i, S.y ) == oldcolor )
			{
				if ( xLeftNotSet )
				{
					S.xl		= i;
					xLeftNotSet	= false;
				}
				dc.SetPixel( i, S.y, newcolor );
				i++;
			}
			if ( i > S.xl )
			{
				S.xr = i - 1;
				PushStack( &S );
				xLeftNotSet = true;
			}
			while ( i <= span.xr && dc.GetPixel( i, S.y ) != oldcolor )
			{
				i++;
			}
		}
	}
}

typedef struct {
	int y, xl, xr;
}Span;
#define stack_size 100
Span	S[stack_size];
int	top = 0;
void SetStackEmpty()
{
	top = 0;
}


bool isStackEmpty()
{
	return(top == 0);
}


bool PushStack( Span *ps )
{
	if ( top < stack_size )
	{
		S[top] = *ps;
		top++;
		return(true);
	}else
		return(false);
}


bool PopStack( Span *ps )
{
	if ( top > 0 )
	{
		top--;
		*ps = S[top];
		return(true);
	}else return(false);
}
```

**算法运行时间比较**

在GraphicFill中，使用 **watch类** 来监控几个不同填充算法执行的时间，watch类的实现请参照 **time1.h** 文件，具体调用请参照`GraphicFillView.cpp`文件中 **OnDraw** 函数。运行四种不同的填充算法的程序运行时间截图在下方。

区域填充算法，边界表示

![image.png](https://upload-images.jianshu.io/upload_images/4630295-ae4c24b2d1824754.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

区域填充算法，内点表示

![image.png](https://upload-images.jianshu.io/upload_images/4630295-89e8b83c707a2ce3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

区域填充扫描线 

![image.png](https://upload-images.jianshu.io/upload_images/4630295-371b0fd705cdf940.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)


堆栈实现

![image.png](https://upload-images.jianshu.io/upload_images/4630295-b83f01a6f1bf2d23.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

