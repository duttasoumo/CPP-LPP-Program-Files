	//q4nas2.cpp : Write a program to calculate transportation cost
	//using North West Corner Method(NWCM).
	#include<iostream.h>
	class NWCM
	{
	public:
  float nwcm(float cost[11][11],float cap[11],float req[11],int nc,int nr);
	};
float NWCM :: nwcm(float cost[11][11],float cap[11],float req[11],int nc,int nr)
	{
	float allot_mat[11][11],s1,s2;
	int i,j,flag;
	int imin,jmin;
	char ch;
	//To test whether the cost matrix is balanced or unbalanced
	s1=s2=0;
	//To get sum of all capacities
		for(i=1;i<=nc;i++)	
		s1=s1+cap[i];
	//To get sum of all requirements
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
	//NWCM iteration starts
	imin=1;
	jmin=1;
	//To initialize all elements of allot_mat[][] matrix to '0'
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			allot_mat[i][j]=0;
		do
		{
		flag=0;
			if(cap[imin]<req[jmin])
			{
			allot_mat[imin][jmin]=cap[imin];
			req[jmin]=req[jmin]-cap[imin];
			cap[imin]=0;
			imin=imin+1;
			}
			else
			{
			allot_mat[imin][jmin]=req[jmin];
			cap[imin]=cap[imin]-req[jmin];
			req[jmin]=0;
			jmin=jmin+1;
			}
		cout<<"Elements in Allotment matrix--->\n";
			for(i=1;i<=nc;i++)
			{
				for(j=1;j<=nr;j++)
				cout<<allot_mat[i][j]<<"\t";
			cout<<"cap["<<i<<"]="<<cap[i]<<endl;
			}
			cout<<"Req :";
			for(i=1;i<=nr;i++)
			cout<<req[i]<<"\t";
  		      cout<<"\nType any character and then press enter key-->";
			cin>>ch;
			for(i=1;i<=nc;i++)
				if(cap[i] !=0 )
				{
				flag=1;
				break;
				}
			for(i=1;i<=nr;i++)
				if(req[i] !=0 )
				{
				flag=1;
				break;
				}
		}while(flag==1);
	//To calculate total transportation cost using NWCM
	s1=0;
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			s1=s1+allot_mat[i][j]*cost[i][j];
	return s1;
	}
	int main()
	{
	float cost[11][11],cap[11],req[11],s;
	int i,j,nc,nr;
	system("clear");
	cout<<endl<<"Enter number of capacities(1-10)=";
	cin>>nc;
	cout<<"Enter number of requirements(1-10)=";
	cin>>nr;
	cout<<endl<<"Enter elements of cost matrix one by one--->\n";
		for(i=1;i<=nc;i++)
			for(j=1;j<=nr;j++)
			{
			cout<<"cost["<<i<<"]["<<j<<"]=";
			cin>>cost[i][j];
			}
	cout<<"Enter capacities one by one--->\n";
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
	cout<<"\nTotal Transportation cost using NWCM="<<s<<endl;
	return 0;
	}

		






 









	



		






		
		


		









