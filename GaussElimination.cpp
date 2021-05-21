	//q1aas1.cpp : Write a program to solve linear simultaneous
	//equations using Gauss Elimination method
	#include<iostream.h>
	class Gauss_Elimination
	{
	private:
	float a[10][10], b[10];
	int n;
	public:
	float x[10];
	Gauss_Elimination()
	{}
	Gauss_Elimination(float a1[10][10],float b1[10],int n1);
	void gauss_elimination();//To implement gauss elimination method
	void display();  // To display roots
	};
Gauss_Elimination :: Gauss_Elimination(float a1[10][10],float b1[10],int n1)
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
	void Gauss_Elimination :: gauss_elimination()
	{
	int i,j,k;
	float am,s;
	// To convert equations to triangular form
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				if( i != j)
				{
				am=a[j][i]/a[i][i];
					for(k=0;k<n;k++)
					a[j][k]=a[j][k]-a[i][k]*am;
				b[j]=b[j]-b[i]*am;
				}
		}
	// To implement back substitution method
	x[n-1]=b[n-1]/a[n-1][n-1];
		for(i=n-2 ; i>=0;i--)
		{
		s=0;
			for(j=i+1;j<n;j++)
			s=s+a[i][j]*x[j];
		x[i]=(b[i]-s)/a[i][i];
		}
	}
	void Gauss_Elimination :: display()
	{
	int i;
		for(i=0;i<n;i++)
		cout<<"Root-"<<(i+1)<<"= "<<x[i]<<endl;
	}
	int main()
	{
	float a[10][10],b[10];
	int i,j,n;
	system("clear");
	cout<<endl<<"Enter number of equations(1-10)=";
	cin>>n;
	cout<<endl<<"Enter co-efficients of your equations--->\n";
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
	Gauss_Elimination GE(a,b,n);
	GE.gauss_elimination();
	GE.display();
	return 0;
	}
















	













	





	
