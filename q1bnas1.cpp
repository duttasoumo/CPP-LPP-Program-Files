	//q1bas1.cpp : Write a program to solve linear simultaneous
	//equations using Matrix Inversion method
	#include<iostream.h>
	
	class Gauss_Jordan
	{
	private:
	float a[10][10], b[10];
	int n;
	public:
	float x[10];
	Gauss_Jordan()
	{}
	Gauss_Jordan(float a1[10][10],float b1[10],int n1);
	void gauss_jordan();//To implement  matrix inversion method
	void display();  // To display roots
	void display_matrix(float x[10][20],int m);
	};
Gauss_Jordan :: Gauss_Jordan(float a1[10][10],float b1[10],int n1)
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
	void Gauss_Jordan :: gauss_jordan()
	{
	int i,j,k,n1;
	float am,s;
	float aug[10][20], inverse[10][10];
	// To contruct initial augmented matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			{
			aug[i][j]=a[i][j];
				if(i==j)
				aug[i][j+n]=1;
				else
				aug[i][j+n]=0;
			}
		display_matrix(aug,n);
	// To get inverse Matrix using Gauss Jordan algorithm
	n1=2*n;
		for(i=0;i<n;i++)
		{
		am=aug[i][i];
			for(j=0;j<n1;j++)
			aug[i][j]=aug[i][j]/am;
			for(j=0;j<n;j++)
			{	
			if(i != j)
			{
			am=aug[j][i];
				for(k=0;k<n1;k++)
				aug[j][k]=aug[j][k]-aug[i][k]*am;
			display_matrix(aug,n);
			}
			}
		}
	// To extract inverse matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			inverse[i][j]=aug[i][j+n];
	// To calculate A-inverse * B and to get roots
		for(i=0;i<n;i++)
		{
		s=0;
			for(j=0;j<n;j++)
			s=s+inverse[i][j]*b[j];
		x[i]=s;
		cout<<endl;
		}
		
	}

	void Gauss_Jordan :: display()
	{
	int i;
		for(i=0;i<n;i++)
		cout<<"Root-"<<(i+1)<<"= "<<x[i]<<endl;
	}
	void Gauss_Jordan :: display_matrix(float x[10][20],int n)
	{
	int i,j;
	int n1;
	char ch;
	n1=2*n;
	system("clear");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n1;j++)
			cout<<x[i][j]<<"\t";
		cout<<endl;
		}
	cout <<endl<<"Type any character and then press enter key--->";
	cin>>ch;
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
	Gauss_Jordan GJ(a,b,n);
	GJ.gauss_jordan();
	GJ.display();
	return 0;
	}
















	













	





	
