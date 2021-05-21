	//mat_fact.cpp : Write a program to solve linear simultaneous
	//equations using Matrix Factorization method
	#include<iostream.h>
	#include<conio.h>
	class Mat_Fact
	{
	public:
		void mat_fact(float x[10][10],float y[10], float xx[10],int n);
		void display(float xx[10],int n);
	};
	void Mat_Fact :: mat_fact(float a[10][10],float b[10], float xx[10],int n)
		{
		int i,j,k,i1,j1;
		float am,s;
		float lower[10][10],upper[10][10];
		float y[10];
		// To initialize lower[][], upper[][] to zeros
			for(i=0;i<n;i++)
				for(j=0;j<n;j++)
				{
				lower[i][j]=0;
				upper[i][j]=1;
				}
		// To calculate all elements of lower[][], upper[][]
			for(i=0;i<n;i++)
			{
			lower[i][i]=1;
				for(j=0;j<n;j++)
					if(i<=j)
					{
					s=0;
					i1=i-1;
						for(k=0;k<=i1;k++)
						s=s+lower[i][k]*upper[k][j];
					upper[i][j]=a[i][j]-s;
					}
					else if(i>j)
					{
					s=0;
					j1=j-1;
						for(k=0;k<=j1;k++)
						s=s+lower[i][k]*upper[k][j];
					lower[i][j]=(a[i][j]-s)/upper[j][j];
					}
			}
		// To calculate y[] using forward substitution method
		y[0]=b[0];
			for(i=1;i<n;i++)
			{
			s=0;
				for(j=0;j<i;j++)
				s=s+lower[i][j]*y[j];
			y[i]=b[i]-s;
			}
		//To calculate roots using back substituion method
		xx[n-1]=y[n-1]/upper[n-1][n-1];
			for(i=(n-2);i>=0;i--)
			{
			s=0;
				for(j=(i+1);j<n;j++)
				s=s+upper[i][j]*xx[j];
			xx[i]=(y[i]-s)/upper[i][i];
			}
		}

		void Mat_Fact :: display(float xx[], int n)
		{
		int i;
			for(i=0;i<n;i++)
			cout<<"root["<<i<<"]="<<xx[i]<<endl;
		}
		void main()
		{
		float a[10][10],b[10],x[10];
		int i,j,n;
		clrscr();
		cout<<endl<<"Enter number of equations=";
		cin>>n;
		cout<<endl<<"Enter coefficients"<<endl;
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
		Mat_Fact MF;
		MF.mat_fact(a,b,x,n);
		MF.display(x,n);
		getch();
		}
