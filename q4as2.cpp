	//q4as2.cpp : Write a program to calculate transportation cost
	// using North West Corner method(NWCM).
	
	#include<iostream.h>
	class NWCM
	{
	public:	
   float nwcm(float cost[11][11],float cap[11],float req[11],int nc,int nr);
	};
float NWCM :: nwcm(float cost[11][11],float cap[11],float req[11],int nc,int nr)
	{
	float allot_mat[11][11],s1,s2;
	int i,j,i1,j1;
	int flag;
	char ch;
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
	//To calculte allotment matrix using NWCM algorithm
	i=1;
	j=1;
		do
		{
		flag=1;
			if(cap[i]<req[j])
			{
			allot_mat[i][j]=cap[i];
			req[j]=req[j]-cap[i];
			cap[i]=0;
			i=i+1;
			}
			else
			{
			allot_mat[i][j]=req[j];
			cap[i]=cap[i]-req[j];
			req[j]=0;
			j=j+1;
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
			if(i>nc && j>nr)
			flag=0;
		}while(flag==1);
	//To calculate Total transportation cost using NWCM
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
	NWCM N;
	s=N.nwcm(cost,cap,req,nc,nr);
	cout<<"\nTotal Tarnsportation cost using NWCM="<<s<<endl;
	return 0;
	}

		
 
