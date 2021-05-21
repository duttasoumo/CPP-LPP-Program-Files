#include<iostream>
using namespace std;
class MatrixFactorisation
{
	public:
		void matrixfactorisation(float a[10][10],float b[10],float x[10],int n);
		void display(float x[10],int n);
};
void MatrixFactorisation::matrixfactorisation(float a[10][10],float b[10],float x[10],int n)
{
	float l[10][10],u[10][10],y[10],s;
	int i,j,k;
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			l[i][j]=0;
			u[i][j]=0;
		}
	
	for(i=0;i<n;i++)
	{
		l[i][i]=1;
		for(j=0;j<n;j++)
		{
			s=0;
			if(i<=j)
			{	
				for(k=0;k<i;k++)
					s+=(l[i][k]*u[k][j]);
				u[i][j]=a[i][j]-s;
			}
			else
			{
				for(k=0;k<j;k++)
					s+=(l[i][k]*u[k][j]);
				l[i][j]=(a[i][j]-s)/u[j][j];
			}
		}
	}
	
	cout<<endl<<"Elements of upper matrix"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<u[i][j]<<"\t";
		cout<<endl;
	}
	
	cout<<endl<<"Elements of lower matrix"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		cout<<l[i][j]<<"\t";
		cout<<endl;
	}
	
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<i;j++)
			s+=(l[i][j]*y[j]);
		y[i]=b[i]-s;
	}
	
	cout<<endl<<"Elements in matrix y[]"<<endl;
	for(i=0;i<n;i++)
		cout<<y[i]<<endl;
		
	for(i=n-1;i>=0;i--)
	{
		s=0;
		for(j=i+1;j<n;j++)
			s+=(u[i][j]*x[j]);
		x[i]=(y[i]-s)/u[i][i];
	}
	display(x,n);
}
void MatrixFactorisation::display(float x[10],int n)
{
	int i;
	cout<<endl<<"Roots of the system of equations"<<endl;
	for(i=0;i<n;i++)
		cout<<"x["<<i+1<<"] = "<<x[i]<<endl;
}
int main()
{
	float a[10][10],b[10],x[10];
	int i,j,n;
	system("clear");
	cout<<"Enter the number of equations : ";
	cin>>n;
	cout<<endl<<"Enter the coefficients"<<endl;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cout<<"a["<<i+1<<"]["<<j+1<<"]=";
			cin>>a[i][j];
		}
		cout<<"b["<<i+1<<"]=";
		cin>>b[i];
	}
	MatrixFactorisation obj;
	obj.matrixfactorisation(a,b,x,n);
	return 0;
}
