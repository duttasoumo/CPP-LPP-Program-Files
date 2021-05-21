	//q3as1.cpp : Write a program to implement Newton Raphson method
	//to calculate all real roots in a given non linear polynomial eqn.
	#include<iostream.h>
	class Newton_Raphson
	{
	public:
	int newton_raphson(double x[]);
	double function_1(double a);
	double function_1d(double a);
	};
	int Newton_Raphson :: newton_raphson(double x[])
	{
	double x1,f1,f2,f3,ff,a,b,c,h;
	int n;
	a=-50;
	f1=function_1(a);
	n=0;
		for(x1=-49.99999;x1<=50;x1=x1+.00001)
		{
		b=x1;
		f2=function_1(b);
		ff=f1*f2;
			if(ff<0)
			{
			c=a+b;
				do
				{
				h=-function_1(c)/function_1d(c);
				c=c+h;
					if(h<0)
					f3=-h;
					else
					f3=h;
				}while(f3>1e-15);
			x[n++]=c;
			}
		a=x1;
		f1=function_1(a);	
		}
	return n;
	}
	double Newton_Raphson :: function_1(double a)
	{
	double y;
	y=a*a-3;
	//y=a*a*a-6*a*a+11*a-6;
	//y=(a-1.1112)*(a-1.1113)*(a-1.1114);
	return y;
	}
	double Newton_Raphson :: function_1d(double a)
	{
	double y;
	y=2*a;
	return y;
	}

	int main()
	{
	double x[10];
	int n,i;
	system("clear");
	Newton_Raphson NR;
	n=NR.newton_raphson(x);
	cout.precision(16);
	cout<<endl<<"Solutions are -->"<<endl;
		for(i=0;i<n;i++)
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	return 0;
	}


























