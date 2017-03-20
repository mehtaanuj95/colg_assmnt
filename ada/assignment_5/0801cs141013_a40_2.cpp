/* 2 partition problem */
#include <bits/stdc++.h>
using namespace std;

bool subsetsum(int set[], int n, int sum)
{
	if(sum == 0)
		return true;
	//n equal 0 and sum > 0
	if(n == 0 && sum > 0)
		return false;
	//last element greater than sum
	if(set[n-1] > sum)
		return subsetsum(set, n-1, sum);

	/*check for two conditions
		includeing the last eleent
		excluding tyhe least element
	*/
	return (subsetsum(set, n-1, sum) || subsetsum(set, n-1, sum - set[n-1]));
}

int main()
{
	int n,s=0;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];
	for(int i = 0;i<n;i++)
		s=s+a[i];
	cout<<"Sum is : "<<s<<endl;
	if(s % 2 != 0)
	{
		cout<<"Cannot be devided"<<endl;
		return 0;
	}
	cout<<subsetsum(a,n,s/2)<<endl;
	return 0;

}