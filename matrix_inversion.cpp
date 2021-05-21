/*To solve linear simultaneous equations using matrix inversion method*/
#include<iostream>
using namespace std;
class Matrix_Inversion
{
 float cof[10][10],b[10],inverse[10][10],aug[10][20],root[10];
 int n;
public:
 void input();
 void elimination();
 void back_sub();
 void rootscal();
 void display();
};
/* Taking the coefficients of the equations*/
void Matrix_Inversion :: input()
{
 int i,j,x,k;
 cout<<" Enter the number of equations : "<<endl;
 cin>>n;
 cout<<" Enter the coefficients of the equations : "<<endl;
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   cout<<endl<<" aug["<<i<<"]["<<j<<"]= ";
   cin>>aug[i][j];
  }
  cout<<" b["<<i<<"]=";
  cin>>b[i];
 }
 k=2*n;
 x=n;
 for(i=0;i<n;i++)
 {
  for(j=n;j<k;j++)
  {
   if(x==j)
   aug[i][j]=1;
   else
   aug[i][j]=0;
  }
  x++;
 }
}
/*Implementing elimination method to create the upper triangular matrix*/
void Matrix_Inversion :: elimination()
{ 
 int i,j,k,c=0,tmp=2*n;
 float z=0;
for(k=0;k<n;k++) 
 {
  for(i=k+1;i<n;i++)
  {
   z=-aug[i][c]/aug[k][c];
   for(j=c;j<tmp;j++)
   { 
	aug[i][j]=aug[i][j]+(z*aug[k][j]);
   }
  }
 c++; 
}
}

/*Implementing back substitution*/
void Matrix_Inversion :: back_sub()
{int i,j,k;
 float s;
 for(i=n;i<(2*n);i++)
 {
 inverse[n-1][i-n]=aug[n-1][n-1]/aug[n-1][i];
  for(j=n-2;j>=0;j--)
  {
    s=0;
    for(k=j+1;k<n;k++)
    s=s+(aug[j][k]*inverse[k][i-n]);
   inverse[j][i-n]=(aug[j][i]-s)/aug[j][j];
  }
 }
} 
/*To calculate the roots of the equation*/
void Matrix_Inversion :: rootscal()
{
 int i,j,sum;
 for(i=0;i<n;i++)
 {sum=0;
   for(j=0;j<n;j++)
    sum=sum+(inverse[i][j]*b[j]);
  root[i]=sum;
 }
}
/* Displaying the roots of the equations*/
void Matrix_Inversion :: display()
{
 int i;
 cout<<" The roots of the equation :";
 for(i=0;i<n;i++)
 {
  cout<<root[i]<<" , ";
}
}  
/*main function*/
int main()
{
 Matrix_Inversion obj;
 obj.input(); 
 obj.elimination();
 obj.back_sub();
 obj.rootscal();
 obj.display();
 return 0;
}
