	//anprog1.cpp : Write a program to solve linear
	//simultaneous equations using Guass seidal
	//method.
	#include<iostream.h>
	class Gauss_Seidal
	{
	private:
	float a[10][10], b[10];
	int n;
	public:
	float x[10];
		Gauss_Seidal()
		{}
		Gauss_Seidal(float a1[10][10],float b1[10],int n1);
		void gauss_seidal();
		void display();
	};
	Gauss_Seidal :: Gauss_Seidal(float a1[10][10],float b1[10],int n1)
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
	void Gauss_Seidal :: gauss_seidal()
		{
		int i,j,flag,itr;
		float s;
		float xg[10],eps[10];
		// To intialize guess value to 0
			for(i=0;i<n;i++)
			xg[i]=0;
		// To implement gauss seidal method
		itr=0;
			do
			{
			flag=1;
			itr=itr+1;
				for(i=0;i<n;i++)
				{
				s=0;
					for(j=0;j<n;j++)
						if(i != j)
						s=s+a[i][j]*xg[j];		
				x[i]=(b[i]-s)/a[i][i];
				eps[i]=x[i]-xg[i];
					if(eps[i]<0)
					eps[i]=-eps[i];
				xg[i]=x[i];
					if(eps[i]>.000001)
					flag=0;
				}
			}while(flag==0);
       cout<<"\nNumber of Iterations taken in gauss seidal method="<<itr<<endl;
		}
	void Gauss_Seidal :: display()
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
	cout<<endl<<"Enter co-efficients of equations--->\n";
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
	Gauss_Seidal GS(a,b,n);
	GS.gauss_seidal();
	GS.display();
	return 0;
	}

