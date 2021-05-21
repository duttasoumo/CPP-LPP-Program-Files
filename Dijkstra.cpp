	//q3as2.cpp : Write a program to implement Dijkstra's Algorithm
	//to find shortest path from one vertex to  all vertices in any 
	//directed or undirected graph
	#include<iostream.h>
	class Dijkstra
	{
	public :
		void dijkstra(float w[11][11],int m,int n);
		int minimum(float d[11][11],int mark[11],int i, int n);
		
	};
	void Dijkstra :: dijkstra(float w[11][11],int m, int n)
	{
	float d[11][11],mw[11][11];
	int mark[11];
	float s;
	int i,j,k,ii;
	//To form mw[][] matrix from w[][] matrix
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(w[i][j]==0)
				mw[i][j]=9999;
				else
				mw[i][j]=w[i][j];
	//To generate Dijkstra's Matrix
		for(i=1;i<=n;i++)
			if(i==m)
			d[1][i]=0;
			else
			d[1][i]=9999;
	//To put initial marking of all vertices
		for(i=1;i<=n;i++)
			if(i==m)
			mark[i]=1;
			else
			mark[i]=0;

	//To generate Dijkstra's Matrix
		for(i=2;i<=n;i++)
		{
			for(ii=1;ii<=n;ii++)
			d[i][ii]=d[i-1][ii];
			for(j=1;j<=n;j++)
				if(j !=i && mark[j]==0)
				{
				s=d[i][m]+mw[m][j];
					if(s>9999)
					s=9999;
					if(s<d[i][j])
					d[i][j]=s;
				}
		
		mark[m]=2;
		//To find next minima
		m=minimum(d,mark,i,n);
		mark[m]=1;
		}
			
	//To display elements Dijkstra's  Matrix
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(d[i][j]==9999)
				cout<<"-\t";
				else
				cout<<d[i][j]<<"\t";
		cout<<endl;
		}

	}
	
	int Dijkstra :: minimum(float d[11][11],int mark[11],int i,int n)
	{
	int j,k;
	float mn;
		for(j=1;j<=n;j++)
			if(d[i][j] !=9999 && mark[j]==0)
			{
			mn=d[i][j];
			k=j;
			break;
			}
	//To find the real minimum value
		for(j=1;j<=n;j++)
			if(d[i][j] !=9999 && mark[j] ==0)
				if(d[i][j]<mn)
				{
				mn=d[i][j];
				k=j;
				}
	return k;
	}
	
	
	int main()
	{
	float w[11][11];
	int i,j,n,c,m;
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
	cout<<"\nEnter vertex number from which you want to calculate dist=";
	cin>>m;
	Dijkstra D;
	D.dijkstra(w,m,n);
	return 0;
	}


	
		

