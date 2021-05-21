	//least1.cpp : Write a program to implement least square
	//fit method
	#include<iostream.h>
	class Least_Square
	{
	public:
		double a[10];
		void least_square(double x[100],double y[100],int m,int n);
		void gauss_elimination(double a1[10][10],double b1[10],int n);	      };
void Least_Square :: least_square(double x[100],double y[100],int m,int n)
	{
	double s1,s2,p;
	int i,j,k,k1,k2;
	double a1[10][10],b1[10];
	//To calculate elements of a1[][] matrix
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
			{
			s1=0;
			k=i+j;
				for(k1=0;k1<m;k1++)
				{
				p=1;
					for(k2=1;k2<=k;k2++)
					p=p*x[k1];
				s1=s1+p;
				}
			a1[i][j]=s1;
			}
	//To calculate elements of b1[] matrix

		for(i=0;i<=n;i++)
		{
		s2=0;
		k=i;
			for(k1=0;k1<m;k1++)
			{
			p=1;
				for(k2=1;k2<=k;k2++)
				p=p*x[k1];
			s2=s2+p*y[k1];
			}
		b1[i]=s2;
		}
	//To Display elements of a1[][]
	system("clear");
	cout<<endl<<"Elements of Matrix a1[][] --->"<<endl;
		for(i=0; i<=n; i++)
		{
			for(j=0; j<=n; j++)
			cout<<a1[i][j]<<"\t";
		cout<<endl;
		}
	cout<<endl<<"Elements of array b1[] --->"<<endl;
		for(i=0;i<=n;i++)
		cout<<b1[i]<<endl;
	// To calculate solutions of simultaneous equations using 
	// Gauss Elimination Method
	gauss_elimination(a1,b1,n);
	cout<<endl<<"Roots of equations are --->"<<endl;
		for(i=0;i<=n;i++)
		cout<<"a-"<<i<<" ="<<a[i]<<endl;
	}
	
 void Least_Square :: gauss_elimination(double a1[10][10],double b1[10],int n)
	{
	int i,j,k;
	double am,s;
	//To get triangular equations
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
				if(i != j)
				{
				am=a1[j][i]/a1[i][i];
					for(k=0;k<=n;k++)
					a1[j][k]=a1[j][k]-a1[i][k]*am;
				b1[j]=b1[j]-b1[i]*am;
				}
		}
	//Back substitution method starts 
	a[n]=b1[n]/a1[n][n];
		for(i=(n-1);i>=0;i--)
		{
		s=0;
			for(j=(i+1);j<=n;j++)
			s=s+a1[i][j]*a[j];
		a[i]=(b1[i]-s)/a1[i][i];
		}
	}

						
	
	int main()
	{
	double x[100],y[100];
	int i,n,m;
	cout.precision(15);
	system("clear");
	cout<<endl<<"Enter number of experimental points(1-100)=";
	cin>>m;
	cout<<"Enter Degree of your your Polynomial(1-10)=";
	cin>>n;
	cout<<endl<<"Enter x-points and y-points --->"<<endl;
		for(i=0;i<m;i++)
		{
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cout<<"y["<<i<<"]=";
		cin>>y[i];
		}
	Least_Square LS;
	LS.least_square(x,y,m,n);
	return 0;
	}

			
	  
