	//q1das1.cpp : Write a program to solve linear simultaneous
	//equations using Jacobi method
	#include<iostream.h>
	class Jacobi
	{
	private:
	float a[10][10], b[10];
	int n;
	public:
	float x[10];
	Jacobi()
	{}
	Jacobi(float a1[10][10],float b1[10],int n1);
	void jacobi();//To implement jacobi method
	void display();  // To display roots
	};
Jacobi :: Jacobi(float a1[10][10],float b1[10],int n1)
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
	void Jacobi :: jacobi()
	{
	int i,j,itr,flag;
	float s,eps[10];
	float xg[10];
	// To initialize all guess values to 0
		for(i=0;i<n;i++)
		xg[i]=0;
	//To begin Jacobi iteration
	itr=0; // itr=number of iterations taken to get all solutions
		do
		{
		flag=1;
		itr=itr+1;
		// To calculate trial roots using guess values
			for(i=0;i<n;i++)
			{
			s=0;
				for(j=0;j<n;j++)
					if( i != j)
					s=s+a[i][j]*xg[j];
			x[i]=(b[i]-s)/a[i][i];
			eps[i]=x[i]-xg[i];
				if(eps[i]<0)
				eps[i]=-eps[i];
			}
			for(i=0;i<n;i++)
			xg[i]=x[i];
		// To test convergence
			for(i=0;i<n;i++)
				if(eps[i]>1e-06)
				{
				flag=0;
				break;
				}
		}while(flag==0);
		cout<<"Total number of iterations="<<itr<<endl;
	}

	void Jacobi :: display()
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
	Jacobi J(a,b,n);
	J.jacobi();
	J.display();
	return 0;
	}
















	













	





	
