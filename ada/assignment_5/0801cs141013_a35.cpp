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
	int n,s;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++)
		cin>>a[i];
	cout<<"Enter a sum to find\n";
	cin>>s;
	cout<<subsetsum(a,n,s)<<endl;
	return 0;

}