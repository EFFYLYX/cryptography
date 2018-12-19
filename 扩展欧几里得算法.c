#include<stdio.h>


int aneuclid(int f,int g)
{
	int x0,y0,x1,y1,x,y,t;
	x0=1;y0=0;x1=0;y1=1;
	x=0;y=1;
	t=g;
	if(g==0)
	{
		x=1;y=0;
		return f;
	}
	int r=f%g;
	int q=(f-r)/g;
	while(r!=0)
	{
		x=x0-q*x1;
		y=y0-q*y1;
		x0=x1;y0=y1;
		x1=x;y1=y;
		f=g;g=r;r=f%g;
		q=(f-r)/g;
	}
	if(x<=0)
		x=x+t;
	return x;
}

int main()
{
	int a,b,t;
	printf("Please input a and b:");
	scanf("%d %d",&a,&b);
	t=aneuclid(a,b);

	printf("%d\n",t);
}
