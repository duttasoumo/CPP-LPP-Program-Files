	//prob-2.cpp : Write a program to input 2 integers and then
	//calculate (i) hcf of 2 numbers, (ii) lcm of 2 numbers
	#include<iostream.h>
	class Hcf_Lcm
	{
	public:
		int hcf(int a,int b);
		int lcm(int a,int b);
	};
	int Hcf_Lcm :: hcf(int a,int b)
		{
		int r;
			while((r=a%b) !=0)
			{
			a=b;
			b=r;
			}
		return b;
		}
	int Hcf_Lcm :: lcm(int a,int b)
		{
		int h,lc;
		h=hcf(a,b);
		lc=a*b/h;
		return lc;
		}
	int main()
	{
	int a,b,h,lc;
	system("clear");
	cout<<endl<<"Enter 1st number=";
	cin>>a;
	cout<<"Enter 2nd number=";
	cin>>b;
	Hcf_Lcm HL;
	h=HL.hcf(a,b);
	lc=HL.lcm(a,b);
	cout<<endl<<" a="<<a<<" b="<<b<<" hcf="<<h<<" lcm="<<lc<<endl;
	return 0;
	}









	







	




