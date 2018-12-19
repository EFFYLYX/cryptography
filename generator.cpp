#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 200

int a[MAX],sign=0;

int sqrtmod(int a,int b,int c)
{ 
	int u=1;
	b=b+1;
	while(b!=1)
	{
    	u=u*a;
    	u=u%c;
    	b--;
	}
	return u;
}

int main()
{
	int m=0,n,b[MAX],j=0,c[MAX],ran,k,i,flag=1,t=1,x;
	for(i=2;i<= MAX;i++)
	{
		flag=1;
		for(n=2;n< i;n++)
			if(i%n==0)	flag=0;
		if (flag != 0)
		{
			a[sign]=i;   
			sign++;
		}
	}
	printf("Please input the order:");
	scanf("%d",&n);
	for(i=0;i<sign;i++)
		if(a[i]>n)
		{
			sign=i;
			break;
		}
	

	for(i=0;i<sign;i++)
		
			if(n%a[i]==0)
			{
				b[j]=a[i]; 
				j++;
			}

	printf("The generator is:");
	
	for(ran=2;ran<n;ran++)
	{
		
		
		m=ran;
		
		for(i=0;i<j;i++)
		{
			
			k=n/b[i];
			t=sqrtmod(m,k,(n+1));
			if(t==1) break;
		}
		if(t!=1)
		{
			printf(" %d ",m);
			
		}
	}
	printf("\n");
	
}
