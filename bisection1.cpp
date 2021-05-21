	//bisection1.cpp : Write a program to implement bisection method
	#include<iostream.h>
	class Bisection
	{
	public:
	
	int bisection(double x[10]);
	double func_1(double x1);
	};
	int Bisection :: bisection(double x[10])
	{
	double a,b,c,x2;
	double f1,f2,f3,ff;
	int n,i;
	a=-10.0;
	f1=func_1(a);
	n=0;
		for(x2=-9.999;x2<=10;x2=x2+.001)
		{
		b=x2;
		f2=func_1(b);
		ff=f1*f2;
			if(ff<0)
			{
				do
				{
				c=(a+b)/2;
				f3=func_1(c);
					if(f1*f3<0)
					{
					b=c;
					f2=func_1(b);
					}
					else if(f2*f3<0)
					{
					a=b;
					b=c;
					f1=func_1(a);
					f2=func_1(b);
					}
					if(f3<0)
					ff=-f3;
					else
					ff=f3;
					if(ff < .00000000000001)
					{
					x[n++]=c;
					break;
						/*
						if(n==0)
						{
						x[n++]=c;
						break;
						}
						else 
						{
						ff=c-f3;	
							if(ff<0)
							ff=-ff;
							if(ff <.000001)
							break;
							else
							{
							x[n++]=c;
							break;
							}
						}
						*/
					}	
						
				}while(1);
			}
		a=x2;
		f1=func_1(a);
		}
	cout.precision(16);
	cout<<endl<<"Number of roots="<<n<<endl;
		for(i=0;i<n;i++)
		cout<<"Root["<<i<<"]="<<x[i]<<endl;
	}
	double Bisection :: func_1(double x)
	{
	double y;
	y=x*x-3;
	//y=x*x*x-x-11;
	//y=x*x*x-3*x+1;
	return y;
	}
	int main()
	{
	double x[10];
	int i,n;
	system("clear");
	Bisection B;
	n=B.bisection(x);
	cout<<endl<<"Roots are--->"<<endl;
		for(i=0;i<n;i++)
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	return 0;
	}
