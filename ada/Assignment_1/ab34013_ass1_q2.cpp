/*
@author: Anuj Bhai Mehta
Description: duplicate entry using '<' operator
Date: Friday, 21 January 2017
usage: g++ ass1_q2.cpp
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];
	for(int i = 0; i < n;i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(!(a[i] < a[j] || a[j] < a[i]))
			{
				cout<<"Duplicate Entry Found at position "<<i<<" and "<<j<<endl;
				exit(0);
			}
		}
	}
	return 0;
}
