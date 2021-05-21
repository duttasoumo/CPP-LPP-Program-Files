/* To implement Simpson's 1/3rd rule*/
#include<iostream>
using namespace std;
class Simpson
{long int n;
 double h;
 public:
 double function1(double);
 void calculation();
};

/* Writing the function which we have to integrate*/
double Simpson :: function1( double x)
{
 double temp=1.0/(1.0+(x*x));
 return temp;
}

/*function to calculate the integration*/
void Simpson :: calculation()
{ long int i;
 double x,s,s1,s2,s3;
 s=s1=s2=s3=0.0;
 cout<<" Enter the number of intervals "<<endl;
 cin>>n;
 h=(1.0-0.0)/(double)n;
 for(i=0;i<=n;i++)
 {
   x=(double)i/(double)n;
   if(i==0 || i==n)
   { s1=s1+function1(x);
   }
   else if(i%2==0)
   {
     s2=s2+function1(x);
   }
   else 
   {
   s3=s3 + function1(x);
   }
 }
s=4.0*(h/3.0)*(s1 + (2.0*s2) + (4.0*s3));
cout<<endl<<" The value of the integration = "<<s;
 }
int main()
{
 Simpson s;
 s.calculation();
 return 0;
}
  
 
