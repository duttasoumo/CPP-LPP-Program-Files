#include<iostream>
using namespace std;
class Newton_Raphson
{
 public:
 int newton_raphson(double x[]);
 double function_1(double );
 double function_1d(double );
};
int Newton_Raphson :: newton_raphson(double x[])
{
 double x1,f1,f2,f3,ff,a,b,c,h;
 int n=0;
 a=-50;
 f1=function_1(a);
 	for(x1=-49.99999;x1<=50;x1=x1+0.00001)
	{
		b=x1;
		f2=function_1(b);
		ff=f1*f2;
		if(ff<0)
		{	
			c=0.5*(a+b);
			do
			{
			h=-function_1(c)/function_1d(c);
			c=c+h;
			if(h<0)
			f3=-h;
			else f3=h;
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
 /*y=(a-1.1112)*(a-1.1113)*(a-1.1114);*/   
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
 cout<<endl<<" solution are ---->"<<endl;
 	for(i=0;i<n;i++)
        cout<<"x["<<i<<"]="<<x[i]<<endl;
	return 0;
} 
 
