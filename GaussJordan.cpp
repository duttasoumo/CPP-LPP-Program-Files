	//q1bas1.cpp : Write a program to solve linear simultaneous
	//equations using Gauss Jordan Matrix Inversion method
	#include<iostream.h>
	class Gauss_Jordan
	{
	private:
	float a[10][10], b[10];
	int n;
	public:
	float x[10];
	float aug[10][20];
	Gauss_Jordan()
	{}
	Gauss_Jordan(float a1[10][10],float b1[10],int n1);
	void gauss_jordan();//To implement gauss elimination method
	void display();  // To display roots
	void display1(); // To display augmented matrix
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
	float inverse[10][10];  // To store inverse of original matrix
	// To create augmented matrix
		for(i=0; i<n;i++)
			for(j=0;j<n;j++)
			{
			aug[i][j]=a[i][j];
				if( i != j)
				aug[i][j+n]=0;
				else
				aug[i][j+n]=1;
			}
	// To display initial augmented matrix
	display1();
	// To implement Gauss Jordan Matrix Inversion Method
		n1=2*n;
		for(i=0;i<n;i++)
		{
		am=aug[i][i];
			for(j=0;j<n1;j++)
			aug[i][j]=aug[i][j]/am;
			for(j=0;j<n;j++)
				if( i != j)
				{
				am=aug[j][i];
					for(k=0;k<n1;k++)
					aug[j][k]=aug[j][k]-aug[i][k]*am;
				}
		//To display modified augmented matrix
		display1();
		}
	// To extract inverse matrix from augmented matrix
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
			inverse[i][j]=aug[i][j+n];
	//To display inverse matrix
		cout<<endl<<"Elements in Inverse Matrix--->"<<endl;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			cout<<inverse[i][j]<<"\t";
		cout<<endl;
		}
	// To calculate roots of equations. Perform a-invese[][]*b[]
	
		for(i=0;i<n;i++)
		{
		s=0;
			for(j=0;j<n;j++)
			s=s+inverse[i][j]*b[j];
		x[i]=s;
		}
	}

	void Gauss_Jordan :: display()
	{
	int i;
		for(i=0;i<n;i++)
		cout<<"Root-"<<(i+1)<<"= "<<x[i]<<endl;
	}
	void Gauss_Jordan :: display1()
	{
	int i,j,n1;
	char ch;
	system("clear");
	n1=2*n;
		for(i=0;i<n;i++)	
		{
			for(j=0;j<n1;j++)
			cout<<aug[i][j]<<"\t";
		cout<<endl;
		}
	cout<<endl<<"Type any key and press enter key--->";
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
















	













	





	
