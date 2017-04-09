#include <bits/stdc++.h>
using namespace std;

int maxcost(int a[][100], int m, int n)
{
	if(n < 0 || m < 0)
		return 0;
	if(n == 0 && m == 0)
		return a[m][n];
	else
	{
		return a[m][n] + max(maxcost(a, m-1, n-1), maxcost(a, m-1, n));
	}
}
void init(int a[][100])
{
	for(int i = 0;i<100;i++)
	{
		for(int j = 0;j < 100;j++)
		{
			a[i][j] = 0;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[100][100];
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j <= i;j++)
		{
			cin>>a[i][j];
		}
	}
	int cost[n];

	for(int i = 0;i<n;i++)
	{
		cost[i] = maxcost(a,3,i);
	}
	int max = cost[0];
	for(int i = 1;i<n;i++)
	{
		if(cost[i] > max)
			max = cost[i];
	}
	cout<<"Max Cost is : "<<max<<endl;
	return 0;
}