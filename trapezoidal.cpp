/* To implement Trapezoidal rule*/
#include<iostream>
using namespace std;
class Trapezoidal
{long int n;
 double h;
 public:
 double function1(double);
 void trapezoidal();
};

/* Writing the function which we have to integrate*/
double Trapezoidal :: function1( double x)
{
 double temp=1.0/(1.0+(x*x));
 return temp;
}

/*function to calculate the integration*/
void Trapezoidal :: trapezoidal()
{ long int i;
 double x,s,s1,s2;
 s=s1=s2=0.0;
 cout<<" Enter the number of intervals "<<endl;
 cin>>n;
 h=(1.0-0.0)/(double)n;
 for(i=0;i<=n;i++)
 {
   x=(double)i/(double)n;
   if(i==0 || i==n)
   { s1=s1+function1(x);
   }
   else 
   {
     s2=s2+function1(x);
   }
 }
s=4.0*(h/2.0)*(s1 + (2.0*s2));
cout<<endl<<" The value of the integration = "<<s;
 }
int main()
{
 Trapezoidal t;
 t.trapezoidal();
 return 0;
}
  
 
