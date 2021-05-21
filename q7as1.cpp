	//q7as1.cpp : Write a program to implement Trapezoidal
	//Rule
	#include<iostream.h>
	class Trapezoidal
	{
	public:
		double trapezoidal(double a,double b, long int n);
		double function_1(double x);
	};
	double Trapezoidal :: function_1(double x)
	{
	double y;
	y=4/(1+x*x);
	return y;
	}
	double Trapezoidal :: trapezoidal(double a,double b,long int n)
	{
	long int i;
	double s1,s2,it;
	double h;
	h=(b-a)/n;
	s1=function_1(a)+function_1(b);
	s2=0;
		for(i=1;i<n;i++)
		s2=s2+function_1(a+i*h);
	it=.5*h*(s1+2*s2);
	return it;
	}
	
	int main()
	{
	double a,b,y;
	long int n;
	system("clear");
	cout<<endl<<"Enter lower limit(a)=";
	cin>>a;
	cout<<"Enter upper limit(b)=";
	cin>>b;
	cout<<"Enter number of intervals=";
	cin>>n;
	cout.precision(15);
	Trapezoidal T;
	y=T.trapezoidal(a,b,n);
	cout<<endl<<"Value of Integral using Trapezoidal Rule="<<y<<endl;
	return 0;
	}

































	













	
