/*
@author : Anuj Bhai Mehta
Description : Calculates x^n using Taylor Series.
Date: Saturday, 21 January 2017
Usage: g++ ass1_q4_2.cpp -lm
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main()
{
	double x,y;
	cout<<"Enter two numbers\n";
	cin>>x>>y;
	double alpha = y*log(x);
	double power[20];
	power[0] = 1;
	power[1] = x;
	power[2] = (power[1] * x)/2;
	for(int i = 3; i <= 19;i++)
	{
		power[i] = (power[i-1]*x)/i;
	}
		
	double result = 0.00;
	for(int i = 0; i <= 19;i++)
	{
		result = result + power[i];
	}
	cout<<result<<endl;
	return 0;
}
