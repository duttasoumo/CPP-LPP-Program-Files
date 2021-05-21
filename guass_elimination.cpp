/* To implement guass elimination method*/
#include<iostream>
using namespace std;
class Guass_Elimination
{
 float cof[10][10],b[10],x[10];
 int n;
public:
 void input();
 void elimination();
 void back_sub();
 void display();
};
/* Taking the coefficients of the equations*/
void Guass_Elimination :: input()
{
 int i,j;
 cout<<" Enter the number of equations : "<<endl;
 cin>>n;
 cout<<" Enter the coefficients of the equations : "<<endl;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   cout<<endl<<" cof["<<i<<"]["<<j<<"]= ";
   cin>>cof[i][j];
  }
  cout<<" b["<<i<<"]=";
  cin>>b[i];
 }
}
/*Implementing elimination method to create the upper triangular matrix*/
void Guass_Elimination :: elimination()
{ 
 int i,j,k,c=0;
 float z=0;
for(k=0;k<n;k++) 
 {
  for(i=k+1;i<n;i++)
  {
   z=-cof[i][c]/cof[k][c];
   for(j=c;j<n;j++)
   { 
	cof[i][j]=cof[i][j]+(z*cof[k][j]);
   }
   b[i]=b[i]+(z*b[k]);
  }
 c++; 
}
}

/*Implementing back substitution*/
void Guass_Elimination :: back_sub()
{int i,j;
 float s;
 x[n-1]=b[n-1]/cof[n-1][n-1];
 for(i=n-2;i>=0;i--)
 {s=0;
  for(j=i+1;j<n;j++)
  s=s+(cof[i][j]*x[j]);
  x[i]=(b[i]-s)/cof[i][i];
 }	
} 

/* Displaying the roots of the equations*/
void Guass_Elimination ::display()
{
 int i;
 cout<<" The roots of the equation :";
 for(i=0;i<n;i++)
  cout<<x[i]<<" , ";
}  
/*main function*/
int main()
{
 Guass_Elimination obj;
 obj.input(); 
 obj.elimination();
 obj.back_sub();
 obj.display();
}
