#include <bits/stdc++.h>
using namespace std;

void upperenv(int a[][3], int n)
{
	int min = a[0][0];
	int max = a[0][1];
	int h = a[0][2];
	for(int i = 1; i < n;i++)
	{
		if(a[i][0] < min)
			min = a[i][0];
		if(a[i][1] > max)
			max = a[i][1];
		if(a[i][2] > 2)
			h = a[i][2];
	}
	cout<<"The coordinates of upper envelope (clockwise) are : "<<endl;
	cout<<"( "<<min<<","<<h<<" )"<<endl;
	cout<<"( "<<max<<","<<h<<" )"<<endl;
	cout<<"( "<<max<<","<<"0"<<" )"<<endl;
	cout<<"( "<<min<<","<<"0"<<" )"<<endl;
}
int main()
{
	int n;
	cout<<"Number of rectangles"<<endl;
	cin>>n;
	int a[n][3];
	for(int i = 0; i < n;i++)
	{
		cin>>a[i][0];
		cin>>a[i][1];
		cin>>a[i][2];
	}
	upperenv(a, n);
	return 0;
}