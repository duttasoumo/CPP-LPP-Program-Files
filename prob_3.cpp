	//prob_3.cpp : Write a program to input 2 integers and then
	//calculate (i) hcf of 2 numbers, (ii) lcm of 2 numbers
	//Use constructor

	#include<iostream.h>
	class Hcf_Lcm
	{
	private:
	int a,b;
	public:
		Hcf_Lcm()
		{}
		Hcf_Lcm(int a1,int b1)
		{
		a=a1;
		b=b1;
		}
		int hcf();
		int lcm();
	};
	
	int Hcf_Lcm :: hcf()
		{
		int r,x,y;
		x=a;
		y=b;
			while((r=x%y) !=0)
			{
			x=y;
			y=r;
			}
		return y;
		}
	int Hcf_Lcm :: lcm()
		{
		int h,lc;
		h=hcf();
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
	Hcf_Lcm HL(a,b);
	h=HL.hcf();
	lc=HL.lcm();
	cout<<endl<<" a="<<a<<" b="<<b<<" hcf="<<h<<" lcm="<<lc<<endl;
	return 0;
	}









	







	




