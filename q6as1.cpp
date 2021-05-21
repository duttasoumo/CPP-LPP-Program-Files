	//q6as1.cpp : Write a program to implement Simpson's 1/3rd
	//Rule
	#include<iostream.h>
	class Simpson
	{
	public:
		double simpson(double a,double b, long int n);
		double function_1(double x);
	};
	double Simpson :: function_1(double x)
	{
	double y;
	y=4/(1+x*x);
	return y;
	}
	double Simpson :: simpson(double a,double b,long int n)
	{
	long int i;
	double s1,s2,s3,is;
	double h;
	h=(b-a)/n;
	s1=function_1(a)+function_1(b);
	s2=s3=0;
		for(i=1;i<n;i++)
			if((i%2)==0)
			s2=s2+function_1(a+i*h);
			else
			s3=s3+function_1(a+i*h);
	is=1.0/3*h*(s1+4*s3+2*s2);
	return is;
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
	cout<<"Enter number of intervals(even number)=";
	cin>>n;
	cout.precision(15);
	Simpson S;
	y=S.simpson(a,b,n);
	cout<<endl<<"Value of Integral using Simpson's 1/3rd Rule="<<y<<endl;
	return 0;
	}

































	













	
