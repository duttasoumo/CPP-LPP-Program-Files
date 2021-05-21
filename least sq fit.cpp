	//q9as1.cpp : Write a program to implement Least Square Fit
	//method to fit a polynomial of degree 'n'
	#include<iostream.h>
	class Least_Square
	{
	public:
		double a[10];
		void least_square(double x[100],double y[100],int m,int n);
		void gauss_elimination(double a1[10][10],double b1[10],int n);	      };
void Least_Square :: least_square(double x[100],double y[100],int m,int n)
	{
	double a1[10][10],b1[10],s1,s2,p;
	int i,j,k,k1,k2;
	//To Calulate co-efficient matrix a1[][] from x[] and y[] points
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
			{
			k=i+j;
			s1=0;
				for(k1=0;k1<m;k1++)
				{
				p=1;
					for(k2=1;k2<=k;k2++)
					p=p*x[k1];
				s1=s1+p;
				}
			a1[i][j]=s1;
			}
	//To calculate b1[] array
		for(i=0;i<=n;i++)
		{
		k=i;
		s2=0;
			for(k1=0;k1<m;k1++)
			{
			p=1;
				for(k2=1;k2<=k;k2++)
				p=p*x[k1];
			s2=s2+y[k1]*p;
			}
		b1[i]=s2;
		}
	//To display elements a1[][] Matrix
	system("clear");
	cout<<endl<<"Elements in a1[][] Matrix--->"<<endl;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			cout<<a1[i][j]<<"\t";
		cout<<endl;
		}
	//To display elements in b1[]
	cout<<endl<<"Elements in b1[] array--->"<<endl;
		for(i=0;i<=n;i++)
		cout<<b1[i]<<endl;
	gauss_elimination(a1,b1,n);
	cout<<endl<<endl<<"Solutions are --->\n";
		for(i=0;i<=n;i++)
	cout<<"a-"<<i<<" ="<<a[i]<<endl;
	}
 void Least_Square :: gauss_elimination(double a1[10][10],double b1[10],int n)
	{
	double am,s;
	int i,j,k;
	//To convert equations to triangular form
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
			{
				if( i != j)
				{
				am=a1[j][i]/a1[i][i];
					for(k=0;k<=n;k++)
					a1[j][k]=a1[j][k]-a1[i][k]*am;
				b1[j]=b1[j]-b1[i]*am;
				}
			}
	//Back Substitution method starts
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
	system("clear");
	cout<<endl<<"Enter number of points(3-100)=";
	cin>>m;
	cout<<"Enter Degree of your Polynomial(1-10)=";
	cin>>n;
	cout<<endl<<"Enter x-points and y-points one by one--->"<<endl;
	cout.precision(15);
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
	

































