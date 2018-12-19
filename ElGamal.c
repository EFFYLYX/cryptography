#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define MAX 200

int m0=0,p,a[MAX],b[MAX],j=0,sign=0;

void getprime()
{
	int ran,i,n,flag=1;
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
	
	srand((unsigned)time(NULL));
	
	while(ran>sign || ran<0)
		ran=rand();	
	p=a[ran];
} 

int gcd(int a,int b)
{
    if(b==0)
        return a;
    return 
        gcd(b,a%b);
}

int aneuclid(int a,int b)
{
	int x0,y0,x1,y1,x,y,s;
	x0=1;y0=0;x1=0;y1=1;
	x=0;y=1;
	if(b==0)
	{
		x=1;y=0;
		return a;
	}
	int r=a%b;
	int q=(a-r)/b;
	while(r!=0)
	{
		x=x0-q*x1;
		y=y0-q*y1;
		x0=x1;y0=y1;
		x1=x;y1=y;
		a=b;b=r;r=a%b;
		q=(a-r)/b;
	}				
	return x;
}	

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

int sqrtt(int a,int b)
{
	int u=1;
	b=b+1;
	while(b!=1)
	{
		u=u*a;
		b--;
	}
	return u;
}

int sqrtxmod(int x,int a,int b,int c)
{
	int u=1;
	b=b+1;
	while(b!=1)
	{
		u=u*a;
		u=u%c;
		b--;
	}
	u=u*x;
	u=u%c;
	return u;
}

int zp(int x)
{
	int i;
	for(i=1;i<x;i++)
		if (gcd(i,x)==1)
		{
			b[j]=i;
			j++;
		}
}

void generator(int w)
{
	int d[MAX],j=0,c[MAX],ran,k,i,t,x,y;

	for(i=0;i<sign;i++)
		if(a[i]>w)
		{
			y=i;
			break;
		}

	for(i=0;i<y;i++)
		
			if(w%a[i]==0)
			{
				d[j]=a[i]; 
				j++;
			}
		
	srand((unsigned)time(NULL));
	while(1)
	{
		
		while(ran<=1 || ran>=w || ran==m0)
			ran=rand();
		m0=ran;
		
		for(i=0;i<j;i++)
		{
			
			k=w/d[i];
			t=sqrtmod(m0,k,(w+1));
			if(t==1) break;
		}
		
		if(t!=1)
		{
			break;
		}
	}
}

int main()
{
	long g,i,arf,beta,k,r,s,x,c,r0,d,w,v,ran,k0,k1,r1,s1,m,l,h,t1,t2=1;
	getprime();
	
	
	generator(p-1);
	
	g=m0;
	
	while(arf<0 || arf>=(p-1))
		arf=rand();
	
	beta=sqrtmod(g,arf,p);
	printf("Public key(p=%d g=%d beta=%d)\tPrivate key(arf=%d)\n",p,g,beta,arf);
	
	while(k<0 || k>=(p-1))
		k=rand();
	printf("k=%d\n",k);
	for(;;)
	{
		printf("\nThe encryption please input 1\n");
		printf("The decryption please input 2\n");
		printf("The signature please input:3\n");
		printf("Check signature please input:4\n");
		printf("Exit please input:0\n"); 
		printf("Input your choice:");
		scanf("%d",&c);
		if(c==1)
		{
			printf("Please input x(encryption):");
			scanf("%d",&x);
			printf("E(x=%d,k=%d)\n",x,k);
			r=sqrtmod(g,k,p);
			s=sqrtxmod(x,beta,k,p);
			printf("Cipher(r=%d s=%d)\n",r,s);
		}
		if(c==2)
		{
			printf("Please input r s(decryption):");
			scanf("%d %d",&r,&s);
			
			r0=aneuclid(r,p);
			if(r0<=0)
				r0=(r0%p+p)%p;
			x=sqrtxmod(s,r0,arf,p);
			printf("Plain(x=%d)\n",x);
		}
		if(c==3)
		{
			printf("Please input m(signature):");
			scanf("%d",&m);
			zp(p-1);	
			
			while(ran<0 || ran>j)
				ran=rand();
			
			k0=b[ran];
			k1=aneuclid(k0,(p-1));
			if(k1<=0)
				k1=(k1%(p-1)+(p-1))%(p-1);
		
			r1=sqrtmod(g,k0,p);
			s1=m*k1%(p-1)-r1*arf%(p-1)*k1%(p-1);
			
			printf("m=%d\tr=%d\ts=%d\n",m,r1,s1);
		}
		if(c==4)
		{
			printf("Please input m r s(verification):");
			scanf("%d %d %d",&m,&r1,&s1);
			l=sqrtmod(beta,r1,p);
			h=sqrtmod(r1,s1,p);
			t1=l*h;
			t1=t1%p;
			t2=sqrtmod(g,m,p);
			if(t1==t2)
				printf("The signature is efficient!\n"); 
			else
				printf("The signature is wrong!\n");
		}
		if(c==0) break;
	}	
}
