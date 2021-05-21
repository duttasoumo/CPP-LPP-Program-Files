	//q52as1.cpp : Write a program to implement 
	//Lagrange interpolation method
	#include<iostream.h>
	class Lagrange
	{
	public:
	float lagrange(float x[50],float y[50],int n,float xx);
	};
float Lagrange :: lagrange(float x[50],float y[50],int n, float xx)
	{
	float diff_mat[50][50];
	float yy;
	float num1,den1;
	int i,j;
	//To calculate differnce matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(i==j)
				diff_mat[i][j]=xx-x[i];
				else
				diff_mat[i][j]=x[i]-x[j];
	cout<<endl<<"Elements in Difference Matrix--->"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<diff_mat[i][j]<<"\t";
		cout<<endl;
		}
	//To calculate value of yy at x=xx
		yy=0;
		for(i=0;i<n;i++)
		{
		num1=1;
		den1=1;
			for(j=0;j<n;j++)
				if(i !=j)
				num1=num1*(xx-x[j]);
			for(j=0;j<n;j++)
				if(i !=j)
				den1=den1*(x[i]-x[j]);
		yy=yy+num1/den1*y[i];
		}
	return yy;
	}
	int main()
	{
	float x[50],y[50],xx,yy;
	int i,n;
	system("clear");
	cout<<endl<<"Enter number of points(1-50)=";
	cin>>n;
	cout<<endl<<"Enter x-points, y-points one by one--->\n";
		for(i=0;i<n;i++)
		{
		cout<<"x["<<i<<"]=";
		cin>>x[i];
		cout<<"y["<<i<<"]=";
		cin>>y[i];
		}
	cout<<"Enter your new x-point=";
	cin>>xx;
	Lagrange L;
	yy=L.lagrange(x,y,n,xx);
	cout<<"x-new="<<xx<<"  y-new="<<yy<<endl;
	return 0;
	}












































	




