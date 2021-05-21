	//trap1.cpp : Write a progrm to implement trapezoidal rule
	#include<iostream.h>
	class Trapezoidal_Rule
	{
	public:
		double trapezoidal_rule(double a,double b,long int n);
		double func_1(double x);
	};
     double Trapezoidal_Rule :: trapezoidal_rule(double a,double b,long int n)
	{
	double y,s1,s2;
	long int i;
	double h;
	h=(b-a)/n;
	s1=s2=0;
	s1=func_1(a)+func_1(b);
		for(i=1;i<n;i++)
		s2=s2+func_1(a+i*h);
	y=.5*h*(s1+2*s2);
	return y;
	}
     double Trapezoidal_Rule :: func_1(double x)
	{
	double y;
	y=4/(1+x*x);
	return y;
	}
	int main()
	{
	double a,b,y;
	long int n;
	system("clear");
	cout<<endl<<"Enter lower limit=";
	cin>>a;
	cout<<"Enter upper limit=";
	cin>>b;
	cout<<"Enter number of Intervals=";
	cin>>n;
	cout.precision(16);
	Trapezoidal_Rule TR;
	y=TR.trapezoidal_rule(a,b,n);
	cout<<endl<<"Value of Integral using Trapezoidal Rule Method="<<y<<endl;
	return 0;
	}


	
