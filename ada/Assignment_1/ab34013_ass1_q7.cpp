/*
@author : Anuj Bhai Mehta
Description : Kth largest number
Date: Monday, 9 January 2017
Usage: g++ ass1_q7.cpp -lm
*/

#include <stdio.h>
#include <iostream>

using namespace std;


int main()
{
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		b[i]=0;
	int temp;
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j< 6; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	for(int i= 0; i < 7;i++)
	{
		int j = 1;
		while(a[i+j] == a[i] + j)
		{	
			b[i]++;
			j++;
		}
		
	}
	/*
	cout<<endl;
	for(int i = 0; i < 7;i++)
		cout<<b[i]<<"  ";
	*/		
	int max = b[0];
	for(int i = 1; i < 7;i++)
	{
		if(b[i] > max)
		max = b[i];
	}
	cout<<max + 1<<endl;
}
