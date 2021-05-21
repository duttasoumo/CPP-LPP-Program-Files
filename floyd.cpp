#include<iostream>
using namespace std;
class Floyd
{
	public:
		void floyd(float w[10][10],int);
		float minimum(float,float);
		void display(float qk[10][10][10],int);
};
float Floyd::minimum(float x,float y)
{
	return (x<y)?x:y;
}
void Floyd::display(float qk[10][10][10],int n)
{
	int i,j,k,c;
	for(k=0;k<=n;k++)
	{
		cout<<"\nElements in qk["<<k+1<<"] Matrix\n";
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				if(qk[k][i][j]==999)
				cout<<"-\t";
				else
				cout<<qk[k][i][j]<<"\t";
			cout<<endl;
		}
		cout<<"Enter any number : ";
		cin>>c;
	}
}
void Floyd::floyd(float w[10][10],int n)
{
	int i,j,k;
	float qk[10][10][10],s;
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(w[i][j]==0)
				qk[0][i][j]=999;
			else
				qk[0][i][j]=w[i][j];
	
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				s=qk[k-1][i][k]+qk[k-1][k][j];
				if(s>999)
					s=999;
				qk[k][i][j]=minimum(qk[k-1][i][j],s);
			}
	
	display(qk,n);
}

int main()
{
	float w[10][10];
	int i,j,n,c;
	system("clear");
	cout<<"Enter the number of vertices : ";
	cin>>n;
	cout<<"Enter 1 for unidirected graph and 0 for directed graph : ";
	cin>>c;
	cout<<"Enter the weight matrix elements"<<endl;
	if(c==1)
	{
		for(i=1;i<=n;i++)
			for(j=i;j<=n;j++)
			{
				cout<<"w["<<i<<"]["<<j<<"] = ";
				cin>>w[i][j];
				w[j][i]=w[i][j];
			}
	}
	else
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
			{
				cout<<"w["<<i<<"]["<<j<<"] = ";
				cin>>w[i][j];
			}
	}
	Floyd f;
	f.floyd(w,n);
	return 0;
}
