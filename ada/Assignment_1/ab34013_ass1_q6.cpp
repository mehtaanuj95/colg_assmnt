/*
@author : Anuj Bhai Mehta
Description : Calculates nth Fibonacci number
Date: Monday, 9 January 2017
Usage: g++ ass1_q6.cpp
*/

#include <stdio.h>
#include <iostream>

using namespace std;

int fibo(int n)
{
	if( n == 0)
		return 0;
	else if(n == 1)
		return 1;
	
	return (fibo(n-1) + fibo (n-2));
}
void fibo_i(int n)
{
	int first = 0;
	int second = 1;
	int third;
	
	while(n-2 >0)
	{
		
		third = first + second;
		
		first = second;
		second = third;
		n--;
	}
	cout<<third;
}
int main()
{
	int n;
	cin>>n;
	cout<<fibo(n-1)<<" : Recursive approach"<<endl;
	fibo_i(n);
	cout<<" : Iterative approach"<<endl;
	
}
