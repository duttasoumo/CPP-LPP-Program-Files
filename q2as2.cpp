	//q2as2.cpp : Write a program to implement Floyd's Algorithm
	//to find shortest path among all vertices in any graph
	#include<iostream.h>
	class Floyd
	{
	public :
		void floyd(float w[11][11],int n);
		void display(float qk[11][11][11],int k ,int n);
		float minimum(float x,float y);
	};
	void Floyd :: floyd(float w[11][11],int n)
	{
	float qk[11][11][11];
	float s;
	int i,j,k;
	//To copy weight matrix to qk[0][][]
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(w[i][j]==0)
				qk[0][i][j]=9999;
				else
				qk[0][i][j]=w[i][j];
	//To generate Floyd's Matrix
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
				{
				s=qk[k-1][i][k]+qk[k-1][k][j];
					if(s>9999)
					s=9999;
				qk[k][i][j]=minimum(qk[k-1][i][j],s);
				}
	//To display elements in  Floyd's Qk[][][] Matrix
		for(k=0;k<=n;k++)
		{
		cout<<"Elements in Qk["<<k<<"] Matrix--->\n";
		display(qk,k,n);
		}
	}
	
	float Floyd :: minimum(float x,float y)
	{
	if(x<y)
	return x;
	else
	return y;
	}
	void Floyd :: display(float qk[11][11][11],int k,int n)
	{
	int i,j,num;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(qk[k][i][j] != 9999)
				cout<<qk[k][i][j]<<"\t";
				else
				cout<<"-\t";
		cout<<endl;
		}
		
		cout<<endl<<"Type some number and then press enter-->"<<endl;
		cin>>num;
		
	}
	int main()
	{
	float w[11][11];
	int i,j,n,c;
	system("clear");
	cout<<"\nEnter number of vertices in your graph(1-10)=";
	cin>>n;
	cout<<"Enter '1' for undirected graph and '0' for directed graph :";
	cin>>c;
		if(c==1)
		{
		//To input weight matrix of an undirected Graph
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


	
		

