	//q4as1.cpp : Write a program to implement Bisection method
	//to calculate all real roots in a given non linear polynomial eqn.
	#include<iostream.h>
	class Bisection
	{
	public:
	int bisection(double x[]);
	double function_1(double a);
	};
	int Bisection :: bisection(double x[])
	{
	double x1,f1,f2,f3,ff,a,b,c;
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
				do
				{
				c=.5*(a+b);
				f3=function_1(c);
					if(f1*f3<0)
					{
					b=c;
					f2=function_1(b);
					}
					else if(f2*f3<0)
					{
					a=b;
					b=c;
					f1=function_1(a);
					f2=function_1(b);
					}
					if(f3<0)
					ff=-f3;
					else
					ff=f3;
					if(ff<.000000000000001)
					{
					x[n++]=c;
					break;
					}
				}while(1);
					
			}
		a=x1;
		f1=function_1(a);
		}
	return n;
	}
	double Bisection :: function_1(double a)
	{
	double y;
	//y=a*a-3;
	//y=a*a*a-6*a*a+11*a-6;
	y=(a-1.1112)*(a-1.1113)*(a-1.1114);
	return y;
	}
	int main()
	{
	double x[10];
	int n,i;
	system("clear");
	Bisection B;
	n=B.bisection(x);
	cout.precision(16);
	cout<<endl<<"Solutions are -->"<<endl;
		for(i=0;i<n;i++)
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	return 0;
	}


























