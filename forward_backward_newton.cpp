/*To implement Newton's Forward and backward interpolation to find the solution*/
#include<iostream>
using namespace std;
class Newton_Inter
{
 float mat[10][10],forward[10][10],backward[10][10],x,u,y,h;
 int n;
public:
 void input();/* To take input of the mat,x,h and compute the forward or backward table 		 depending on the value of x. Also computing u*/
 void display();
 void calculate();
};

void Newton_Inter :: input()
{int i,j,tmp;
 cout<<" Enter the number of inputs "<<endl;
 cin>>n;
 cout<<" Enter the values "<<endl;
 for(i=0;i<n;i++)
 {
  cout<<endl<<"x"<<i<<"= ";
  cin>>mat[i][0];
  cout<<endl<<"y"<<i<<"= ";
  cin>>mat[i][1];
 }
 cout<<" Enter the value of x ";
 cin>>x;
 h=mat[1][0]-mat[0][0];
 tmp=n/2;
 if(x<=mat[tmp][0])
 {/*finding forward derivative*/
  for(i=0;i<n;i++)
  {for(j=0;j<n;j++)
   forward[i][j]=0;
  }
  for(i=0;i<n;i++)
  forward[i][0]=mat[i][1];
  for(i=0;i<n;i++)
  {
   for(j=0;j<n-1-i;j++)
	forward[j][i+1]=forward[j+1][i]-forward[j][i];
   
  }
 u=(x-mat[0][0])/h;
 cout<<" u = "<<u;
 }
 else
  {/*finding the backward derivative*/
   for(i=0;i<n;i++)
   {for(j=0;j<n;j++)
    backward[i][j]=0;
   }
   for(i=0;i<n;i++)
   backward[i][0]=mat[i][1];
   for(i=0;i<n;i++)
    {
	for(j=0;j<n-1-i;j++)
	 backward[j+1][i+1]=backward[j+1][i]-backward[j][i];
    }
   u=(x-mat[n-1][0])/h;
   }
 }
 void Newton_Inter :: calculate()
 {
  float mul=1.0;
  int i,fact=1,j,tmp=n/2;
  if(x<=mat[tmp][0])/*forward interpolation formulation*/
  {y=mat[0][1];/* y=y0*/
   for(i=0;i<n-1;i++)
   {
    for(j=1;j<=i+1;j++)/*finding the factorial*/
    fact*=j;
    cout<< " fact = "<<fact;
    mul=(mul*(u-i))/(float)fact;
    cout<<" mul = "<<mul;
    y=y+(mul*forward[0][i+1]);  
  cout<<" y = "<<y; 
}
  }
 else /*backward interpoltion formula calculation*/
 {y=mat[n-1][1];/* y=yn*/
   for(i=0;i<n-1;i++)
   {
    for(j=1;j<=i+1;j++)/*finding the factorial*/
    fact*=j;
    mul=(mul*(u+i))/(float)fact;
    y=y+(mul*backward[n-1][i+1]);
 
   }
  }
}

void Newton_Inter :: display()
{int i,j,tmp=n/2;
 if(x<=mat[tmp][0])/*display forward difference table*/
 {cout<<endl;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   cout<<forward[i][j]<<"\t";
   cout<<endl;
  }
 }
 else /*displaying backward difference table*/
 {cout<<endl;
  for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   cout<<backward[i][j]<<"\t";
   cout<<endl;
  }
 }
cout<<" Value of the interpolation "<<y;
}
int main()
{
 Newton_Inter obj;
 obj.input();
 obj.calculate();
 obj.display();
 return 0;
} 
  \
