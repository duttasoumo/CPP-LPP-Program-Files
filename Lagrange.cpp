#include<iostream>
using namespace std;
class Lagrange
{
	public:
		float lagrange(float xn[10],float y[10],int,float);
};
float Lagrange::lagrange(float xn[10],float y[10],int n,float x)
{
	float ld[10][10],yn,p1,p2;
	int i,j;
	yn=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			if(i==j)
				ld[i][j]=x-xn[j];
			else
				ld[i][j]=xn[i]-xn[j];
		}
	for(i=0;i<n;i++)
	{
		p1=1;
		p2=1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				p1*=ld[j][j];
				p2*=ld[i][j];
			}
		}
		yn+=(p1/p2)*y[i];
	}
	return yn;
}
int main()
{
	float xn[10],y[10],x,yn;
	int i,n;
	cout<<"Enter the number of points = ";
	cin>>n;
	cout<<"Enter the x and y co ordinates"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"x["<<i+1<<"] = ";
		cin>>xn[i];
		cout<<"y["<<i+1<<"] = ";
		cin>>y[i];
	}
	cout<<"Enter the value of the point = ";
	cin>>x;
	cout.precision(15);
	Lagrange l;
	yn=l.lagrange(xn,y,n,x);
	cout<<"y[x] = "<<yn<<endl;
	return 0;
}
