//1(c) Solve Linear Simultaneous Equations using Gauss Seidal.
#include<iostream>
using namespace std;
class Gauss_Seidal
{
	private:
		float a[10][10],b[10];
		int n;
	public:
		float x[10];
		Gauss_Seidal()
		{}
		Gauss_Seidal(float a1[10][10],float b1[10],int n1);
		void gauss_seidal();//to implement guass seidal method
		void display();//to display roots
};
Gauss_Seidal :: Gauss_Seidal(float a1[10][10], float b1[10], int n1)
{
	int i,j;
        n=n1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	        a[i][j]=a1[i][j];
	b[i]=b1[i];
 	}
}
void Gauss_Seidal ::gauss_seidal()
{int i,j,itr,flag;
 float s,xg[10],eps[10];
 //To initialize all guass values to 0
   for(i=0;i<n;i++)
   xg[i]=0;
 //To begin Gauss Seidal iteration
        itr=0;//itr=number of iterations taken to get all solutions
        do
	{
        flag=1;
	itr=itr+1;
	//To calculate trial roots using guess values
	for(i=0;i<n;i++)
	{
	s=0;
		for(j=0;j<n;j++)
		 if( i!=j)
		 s=s+a[i][j]*xg[j];
	x[i]=(b[i]-s)/a[i][i];
	eps[i]=x[i]-xg[i];
		if(eps[i]<0)
		eps[i]=-eps[i];
	xg[i]=x[i];
	}
//To test convrgence
 for(i=0;i<n;i++)
 	if(eps[i]>1e-06)
	{
	flag=0;
	break;
	}
}while(flag==0);
 cout<<" Total number of iterations ="<<itr<<endl;   
} 
 
void Gauss_Seidal :: display()
{
 int i;
  for(i=0;i<n;i++)
  cout<<"Root -"<<(i+1)<<"= "<<x[i]<<endl;
}
int main()
{
 float a[10][10],b[10];
 int i,j,n;
 system("clear");
 cout<<" enter number of equations(1-10)= ";
 cin>>n;
 cout<<endl<<" enter co-efficient of your equatons--->";
   for(i=0;i<n;i++)
   {
	for(j=0;j<n;j++)
	{
	cout<<"a["<<i<<"]["<<j<<"]=";
	cin>>a[i][j];
	}
   cout<<"b["<<i<<"]=";
   cin>>b[i];
   }
 Gauss_Seidal GS(a,b,n);
 GS.gauss_seidal();
 GS.display();
 return 0;
}	
 
