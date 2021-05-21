	//least_fit.cpp : Write a program to implement least square fit method
	#include<iostream.h>
	class Least_Square_Fit
	{
	public:
	double a[10];
	void least_square_fit(double x[100],double y[100],int m,int n);
	void gauss_elimination(double a1[10][10],double b1[10],int n);
	};
	void Least_Square_Fit :: least_square_fit(double x[100],double y[100],int m,int n)
	{
	double s1,s2,p;
	int i,j,k,k1,k2;
	double a1[10][10],b1[10];
	//To calculate coefficient matrix a1[][]
		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
			{
			k=i+j;
			//p=1;
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
	//To calculate coefficient b1[]
		for(i=0;i<=n;i++)
		{
		s2=0;
		//p=1;
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
	//To display all co-efficients
	cout.precision(16);
	cout<<endl<<"Elements in a1[][] Matrix--->"<<endl;
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			cout<<a1[i][j]<<"\t";
		cout<<endl;
		}
	cout<<"Elements in b1[] array--->"<<endl;
		for(i=0;i<=n;i++)
		cout<<b1[i]<<endl;
	}
	int main()
	{
	double x[100],y[100];
	int i,n,m;
	system("clear");
	cout<<endl<<"Enter number of points(1-100)=";
	cin>>m;
	cout<<endl<<"Enter x-points, y-points one by one--->"<<endl;
		for(i=0;i<m;i++)
		{
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cout<<"y["<<i<<"]=";
		cin>>y[i];
		}
	cout<<"Enter order of polynomial=";
	cin>>n;
	Least_Square_Fit LSF;
	LSF.least_square_fit(x,y,m,n);
	return 0;
	}



		
