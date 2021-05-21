	//q5nas2.cpp : Write a program to implement Matrix Minima method
	//to calculate transportation cost
	#include<iostream.h>
	class MAT_MIN
	{
	public:	
  float mat_min(float cost[11][11],float cap[11],float req[11],int nc,int nr);
	};
float MAT_MIN :: mat_min(float cost[11][11],float cap[11],float req[11],int nc,int nr)
	{
	float allot_mat[11][11],s1,s2;
	int i,j,i1,j1;
	int imin,jmin;
	int flag;
	char ch;
float mn;
	//To test whether the matrix is balanced or unbalanced
	s1=s2=0;
		for(i=1;i<=nc;i++)
		s1=s1+cap[i];
		for(i=1;i<=nr;i++)
		s2=s2+req[i];
		if(s1<s2)
		{
		nc=nc+1;
		cap[nc]=s2-s1;
			for(i=1;i<=nr;i++)
			cost[nc][i]=0;
		}
		else if(s2<s1)
		{
		nr=nr+1;
		req[nr]=s1-s2;
			for(i=1;i<=nc;i++)
			cost[i][nr]=0;
		}
	//To initialize allot_mat[][] matrix to '0'
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			allot_mat[i][j]=0;
	//To calculte allotment matrix using Matrix Minima method
	imin=1;
	jmin=1;
		do
		{
		flag=1;
		//To find index of minimum cost in cost[][] matrix
			
			for(i=1;i<=nc;i++)
			{
				for(j=1;j<=nr;j++)
				if(cap[i]!=0 && req[j]!=0 )
				{
				mn=cost[i][j];
				imin=i;
				jmin=j;
				flag=0;
				break;
				}
				if(flag==0)
				break;
			}
			
			for(i=1;i<=nc;i++)
			{
				for(j=1;j<=nr;j++)
				if(cap[i]!=0 && req[j]!=0 && cost[i][j]<mn)
				{
				mn=cost[i][j];
				imin=i;
				jmin=j;
				}
			}
		
			if(cap[imin]<req[jmin])
			{
			allot_mat[imin][jmin]=cap[imin];
			req[jmin]=req[jmin]-cap[imin];
			cap[imin]=0;
			}
			else
			{
			allot_mat[imin][jmin]=req[jmin];
			cap[imin]=cap[imin]-req[jmin];
			req[jmin]=0;
			}
		cout<<"Elements in allotment Matrix --->\n";
			for(i1=1;i1<=nc;i1++)
			{
				for(j1=1;j1<=nr;j1++)
				cout<<allot_mat[i1][j1]<<"\t";
			cout<<"Cap["<<i1<<"]="<<cap[i1]<<endl;
			}
		cout<<"Req: ";
		for(i1=1;i1<=nr;i1++)
		cout<<req[i1]<<"\t";
		cout<<"\nType any number and Press enter key to continue--->";
		cin>>ch;
		flag=0;
			for(i=1;i<=nc;i++)
				if(cap[i]!=0)
				{	
				flag=1;
				break;
				}
			for(i=1;i<=nr;i++)
				if(req[i]!=0)
				{
				flag=1;
				break;
				}
			
		}while(flag==1);
	//To calculate Total transportation cost using Matix Minima
	s1=0;
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			s1=s1+allot_mat[i][j]*cost[i][j];
	return s1;
	}
	int main()
	{
	float cost[11][11],s,cap[11],req[11];
	int i,j,nc,nr;
	system("clear");
	cout<<"\nEnter Number of capacities(1-10)=";
	cin>>nc;
	cout<<"Enter number of requirements(1-10)=";
	cin>>nr;
	cout<<endl<<"Enter elements of cost Matrix--->\n";
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			{
			cout<<"cost["<<i<<"]["<<j<<"]=";
			cin>>cost[i][j];
			}
	cout<<endl<<"Enter capacities one by one--->\n";
		for(i=1;i<=nc;i++)
		{
		cout<<"capacity["<<i<<"]=";
		cin>>cap[i];
		}
	cout<<"Enter requirements one by one--->\n";
		for(i=1;i<=nr;i++)
		{
		cout<<"requirement["<<i<<"]=";
		cin>>req[i];
		}
	MAT_MIN M;
	s=M.mat_min(cost,cap,req,nc,nr);
	cout<<"\nTotal Tarnsportation cost using Matrix Minima="<<s<<endl;
	return 0;
	}

		
 
