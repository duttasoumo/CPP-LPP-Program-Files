	//simp1.cpp : Write a progrm to implement Simpson's 1/3rd rule
	#include<iostream.h>
	class Simpson_1_3RD_Rule
	{
	public:
		double simpson_1_3rd_rule(double a,double b,long int n);
		double func_1(double x);
	};
	double Simpson_1_3RD_Rule :: simpson_1_3rd_rule(double a,double b,long int n)
	{
	double y,s1,s2,s3;
	long int i;
	double h;
	h=(b-a)/n;
	s1=s2=s3=0;
	s1=func_1(a)+func_1(b);
		for(i=1;i<n;i++)
			if((i%2)==0)
			s2=s2+func_1(a+i*h);
			else
			s3=s3+func_1(a+i*h);
	y=1.0/3.0*h*(s1+4*s3+2*s2);
	return y;
	}
     double Simpson_1_3RD_Rule :: func_1(double x)
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
	Simpson_1_3RD_Rule SR;
	y=SR.simpson_1_3rd_rule(a,b,n);
	cout<<endl<<"Value of Integral using Simpson's 1/3rd Rule="<<y<<endl;
	return 0;
	}


	
