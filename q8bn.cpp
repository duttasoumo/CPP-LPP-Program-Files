	//q8bn.cpp : Write a program to implement 4-th order Runge Kutta
	//method
	#include<iostream.h>
	class Runge4
	{
	public:
	double runge4(double x0,double y0,double h);
	double function1(double x,double y);
	};
	double Runge4 :: runge4(double x0,double y0,double h)
	{
	double k1,k2,k3,k4,y;
	k1=h*function1(x0,y0);
	k2=h*function1(x0+.5*h,y0+.5*k1);
	k3=h*function1(x0+.5*h,y0+.5*k2);
	k4=h*function1(x0+h,y0+k3);
	y=y0+1.0/6.0*(k1+2*k2+2*k3+k4);
	return y;
	}
	double Runge4 :: function1(double x, double y)
	{
	double y1;
	y1=y+0*x;
	return y1;
	}
	int main()
	{
	double x[100],y[100];
	double x0,y0,xn,xx,yy;
	double h;
	int n,i;
	system("clear");
	cout<<endl<<"Enter x0=";
	cin>>x0;
	cout<<"Enter y0=";
	cin>>y0;
	cout<<"Enter step size (h) =";
	cin>>h;
	cout<<"Enter xn=";
	cin>>xn;
	x[0]=x0;
	y[0]=y0;
	xx=x0;
	yy=y0;
	cout.precision(15);
	Runge4 R;
	n=0;
		for(xx=x0;xx<=xn;xx=xx+h)
		{
		n=n+1;
		x[n]=x0+n*h;
		y[n]=R.runge4(xx,yy,h);
		xx=x[n];
		yy=y[n];
		}
	cout<<endl<<"Solutions of Differential Equation--->"<<endl;
		for(i=0;i<=n;i++)
		cout<<"x["<<i<<"]="<<x[i]<<" y["<<i<<"]="<<y[i]<<endl;
	return 0;
	}

