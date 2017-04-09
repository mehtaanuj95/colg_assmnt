/* Longest Palindromic Subsequence Recursive Solution */
#include <bits/stdc++.h>
using namespace std;

int lps(char *s, int i, int j)
{
	//Case 1
	if(i == j)
		return 1;
	//Case 2
	if(s[i] == s[j] && j == i+1)
		return 2;
	//Case 3
	if(s[i] == s[j])
		return lps(s, i+1,j-1) + 2;
	//Case 4
	return max(lps(s, i+1,j), lps(s, i,j-1));
}
int main()
{
	char s[]="abcdgcdeeab";
	int n = strlen(s);
	cout<<lps(s,0,n-1)<<endl;
	return 0;
}
