#include<iostream>
using namespace std;
class LeastSquareFit
{
	public:
		double a[10];
		void leastsquarefit(double x[100],double y[100],int,int);
		void gausselimination(double a1[10][10],double b1[10],int);
		void display(int);
};
void LeastSquareFit::leastsquarefit(double x[100],double y[100],int m,int n)
{
	double a1[10][10],b1[10],s1,s2,p;
	int i,j,k,k1,k2;
	for(i=0;i<=m;i++)
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
	cout<<"Elements in matrix a[][]"<<endl;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			cout<<a1[i][j]<<"\t";
		cout<<endl;
	}
	cout<<"Elements in matrix b[]"<<endl;
	for(i=0;i<=n;i++)
		cout<<b1[i]<<endl;
	gausselimination(a1,b1,n);
}
void LeastSquareFit::gausselimination(double a1[10][10],double b1[10],int n)
{
	int i,j,k;
	float am,s;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
			if(i!=j)
			{
				am=a1[j][i]/a1[i][i];
				for(k=0;k<=n;k++)
					a1[j][k]=a1[j][k]-a1[i][k]*am;
				b1[j]=b1[j]-b1[i]*am;
			}
	}
	a[n]=b1[n]/a1[n][n];
	for(i=n-1;i>=0;i--)
	{
		s=0;
		for(j=i+1;j<=n;j++)
			s=s+a1[i][j]*a[j];
		a[i]=(b1[i]-s)/a1[i][i];
	}
	display(n);
}
void LeastSquareFit::display(int n)
{
	int i;
	cout<<"Required polynomial"<<endl;
	for(i=0;i<=n;i++)
	{
		if(i==0)
			cout<<a[i];
		else if(i==1)
			cout<<" + "<<a[i]<<" x";
		else if(i>1)
			cout<<" + "<<a[i]<<" x^"<<i;
	}
	cout<<endl;
}
int main()
{
	double x[100],y[100];
	int i,n,m;
	system("clear");
	cout<<"Enter the number of points = ";
	cin>>m;
	cout<<"Enter the degree of the polynomial = ";
	cin>>n;
	cout<<"Enter the x and y co ordinates"<<endl;
	for(i=0;i<m;i++)
	{
		cout<<"x["<<i+1<<"] = ";
		cin>>x[i];
		cout<<"y["<<i+1<<"] = ";
		cin>>y[i];
	}
	cout.precision(15);
	LeastSquareFit s;
	s.leastsquarefit(x,y,m,n);
	return 0;
}
