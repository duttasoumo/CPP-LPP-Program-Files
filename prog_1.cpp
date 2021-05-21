	//prob_1.cpp : Write a program to input 2 integers and then calculate
	//sum,average of 2 integers.
	#include<iostream.h>
	int main()
	{
	int a,b,s;
	float avg;
	system("clear");
	cout<<endl<<"Enter a=";
	cin>>a;
	cout<<"Enter b=";
	cin>>b;
	s=a+b;
	avg=(float)s/2;
	cout<<" a="<<a<<" b="<<b<<" Sum="<<s<<" Average="<<avg;
	return 0;
	}

