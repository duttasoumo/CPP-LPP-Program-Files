	//q2as1.cpp : Write a program to solve linear 
	//simultaneous equations using matrix Factorization
	//method.
	#include<iostream.h>
	class Mat_Fact
	{
	public:
   void mat_fact(float a[10][10],float b[10],int n,float x[10]);
	void display(float x[10],int n);	
	};
void Mat_Fact :: mat_fact(float a[10][10],float b[10],int n,float x[10])
	{
	float lower[10][10],upper[10][10];
	float s;
	float y[10];
	int i,j,k;
	//To calculate lower[][] and upper[][] matrices
	//To initialize lower[][] and upper[][] matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
			lower[i][j]=0;
			upper[i][j]=0;
			}
		for(i=0;i<n;i++)
		{
		lower[i][i]=1;
			for(j=0;j<n;j++)
				if(i<=j)
				{
				s=0;
					for(k=0;k<i;k++)
				s=s+lower[i][k]*upper[k][j];
				upper[i][j]=a[i][j]-s;
				}
				else if(i>j)
				{
				s=0;
					for(k=0;k<j;k++)
				s=s+lower[i][k]*upper[k][j];
			lower[i][j]=(a[i][j]-s)/upper[j][j];
				}
		}
	//To display elements of upper[][], lower[][]
	cout<<endl<<"Elements in upper[][] --->"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<upper[i][j]<<"\t";
		cout<<endl;
		}
	
	cout<<endl<<"Elements in lower[][] --->"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<lower[i][j]<<"\t";
		cout<<endl;
		}
	//To calculate elements in y[] using Forward Substition
	//method
	y[0]=b[0];
		for(i=1;i<n;i++)
		{
		s=0;
			for(j=0;j<i;j++)
			s=s+lower[i][j]*y[j];
		y[i]=b[i]-s;
		}
	cout<<endl<<"Elements in y[] --->"<<endl;
		for(i=0;i<n;i++)
		cout<<y[i]<<endl;
	// To calculate roots using Back substitution method
	x[n-1]=y[n-1]/upper[n-1][n-1];
		for(i=(n-2);i>=0;i--)
		{
		s=0;
			for(j=(i+1);j<n;j++)
			s=s+upper[i][j]*x[j];
		x[i]=(y[i]-s)/upper[i][i];
		}
	}
		
	void Mat_Fact :: display(float x[10],int n)
	{
	int i;
	cout<<endl<<"Roots are--->"<<endl;
		for(i=0;i<n;i++)
		cout<<"x["<<i<<"]="<<x[i]<<endl;
	}
	int main()
	{
	float a[10][10],b[10],x[10];
	int i,j,n;
	system("clear");
	cout<<endl<<"Enter number of equations(1-10)=";
	cin>>n;
	cout<<endl<<"Enter all co-efficients --->"<<endl;
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
	cout.precision(7);
	Mat_Fact MF;
	MF.mat_fact(a,b,n,x);
	MF.display(x,n);
	return 0;
	}











	










	










































		



	









