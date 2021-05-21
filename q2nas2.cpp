	//q2nas2.cpp : Write a program to implement Floyd's algorithm
	//to calculate shortest path among all vertices in any graph
	#include<iostream.h>
	class Floyd
	{
	public:
		void floyd(float w[11][11],int n);
		float minimum(float x,float y);
		void display(float qk[11][11][11],int n);
	};
	float Floyd :: minimum(float x,float y)
	{
		if(x<y)
		return x;
		else
		return y;
	}
	void Floyd :: display(float qk[11][11][11],int n)
	{
	int i,j,k,c;
		for(k=0;k<=n;k++)
		{
		cout<<"\nElements in qk["<<k<<"] Matrix--->\n";
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					if(qk[k][i][j]==9999)
					cout<<"-\t";
					else
					cout<<qk[k][i][j]<<"\t";
			cout<<endl;
			}
		cout<<"\nType any number and press enter key--->";
		cin>>c;
		}
	}
	void Floyd :: floyd(float w[11][11],int n)
	{
	int i,j,k;
	float qk[11][11][11],s;
	//To contruct qk[0][][] matrix from weight matrix
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(w[i][j]==0)
				qk[0][i][j]=9999;
				else
				qk[0][i][j]=w[i][j];
	//To construct qk[1][][],qk[2][][]  etc.

		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
				s=qk[k-1][i][k]+qk[k-1][k][j];
					if(s>9999)
					s=9999;
				qk[k][i][j]=minimum(qk[k-1][i][j],s);
				}
	
	//To display Floyd's matrices
	
	display(qk,n);
	}

	int main()
	{
	float w[11][11];
	int i,j,n,c;
	system("clear");
	cout<<endl<<"Enter number of vertices(1-10)=";
	cin>>n;
	cout<<"Enter '1' for undirected graph and '0' for directed graph :";
	cin>>c;
	cout<<endl<<"Enter elements in your weight matrix"<<endl;
		if(c==1)
		{
			for(i=1;i<=n;i++)
				for(j=i;j<=n;j++)
				{
				cout<<"w["<<i<<"]["<<j<<"]=";
				cin>>w[i][j];
				w[j][i]=w[i][j];
				}
		}
		else
		{
			
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
				cout<<"w["<<i<<"]["<<j<<"]=";
				cin>>w[i][j];
				}
		}
	Floyd F;
	F.floyd(w,n);
	return 0;
	}

				
















	




