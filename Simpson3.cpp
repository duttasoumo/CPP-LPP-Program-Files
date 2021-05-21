/*Calculate the value of the intergral using simpson's 1/3rd rule
I(1,0)4dx/1+x^2 */
#include<iostream>
using namespace std;
class Simpson3
{
	public:
		double simpson(double a,double b, long int n);
		double function_1(double x);
};
double Simpson3 :: function_1(double x)
{
	double y;
	y=4/(1+x*x);
	return y;
}
double Simpson3 :: simpson(double a,double b,long int n)
{	double x;
	long int i;
	double s1,s2,s3;
	double h,is;
	h=(b-a)/n;
	s2=s3=s1=0;
	for(i=0;i<=n;i++)
	  {
		x=(double)i/(double)n;
		if(i==0 || i==n)
		s1=s1+function_1(x);
		else if((i%3)==0)
		s3=s3+function_1(x);
 		else
		s2=s2+function_1(x);}
	is=3.0/8.0*h*(s1+(3*s2)+(2*s3));
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
	cout<<"Enter number of intervals=";
	cin>>n;
	Simpson3 S;
	y=S.simpson(a,b,n);
	cout<<endl<<"Value of Integral using Simpson Rule="<<y<<endl;
	return 0;
}
