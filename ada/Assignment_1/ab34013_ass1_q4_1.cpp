/*
@author : Anuj Bhai Mehta
Description : calculates x^n using logirithm and exponential functions.
Date: Saturday, 21 January 2017
Usage: g++ ass1_q4_1.cpp -lm
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
	double result;
	result = exp(alpha);
	cout<<result<<endl;
	return 0;
}
