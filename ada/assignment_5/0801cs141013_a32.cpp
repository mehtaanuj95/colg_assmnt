/* 3 strings Longest Common Sequence Dynamic Programming Approach */
#include <bits/stdc++.h>
using namespace std;

int max3(int a, int b, int c)
{
	if(a > b)
	{
		if(a > c)
			return a;	
		return c;
	}
	else
	{
		if(b > c)
			return b;
		return c;
	}
}
void lcs(char *A, char *B, char* C, int m, int n, int p)
{
	int len[m+1][n+1][p+1];
	for(int i = 0;i<m+1;i++)
		for(int j = 0;j<n+1;j++)
			for(int k = 0;k<p+1;k++)
				len[i][j][k]=0;

	for(int i = 0;i<= m;i++)
	{
		for(int j = 0;j<=n; j++)
		{
			for(int k = 0;k<=p;k++)
			{
				//if both are 0	
				if(i == 0 || j == 0 || p == 0)			
					len[i][j][k] = 0;
				//if last characters match
				else if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
					len[i][j][k] = 1 + len[i-1][j-1][k-1];
				//if last characters do not match
				else        
					len[i][j][k] = max3(len[i-1][j][k], len[i][j-1][k], len[i][j][k-1]);
			}
			
		}
	}
	cout<<"Length is : "<<len[m][n][p]<<endl;
	int index = len[m][n][p];
	char s[index+1];
	s[index] = '\0';
	int i = m, j = n, k = p;
	while(i > 0 && j > 0 && k > 0)
	{
		//end char match
		if(A[i-1] == B[j-1] && B[j-1] == C[k-1])
		{
			s[index-1] = A[i-1];
			i--;
			j--;
			k--;
			index--;
		}
		//end char do not match
		else if(A[i-1] > B[j-1])
		{
			if(A[i-1] > C[k-1])
				i--;
			else
				k--;
		}
		else
		{
			if(B[j-1] > C[k-1])
				j--;
			else
				k--;
		}

	}
	cout<<s<<endl;;
}

int main()
{
	char A[] = "GXTXAYB";
 	char B[] = "AGGTAB";
 	char C[] = "AGAB";

	int m = strlen(A);
    int n = strlen(B);
    int p = strlen(C);
    lcs( A, B, C, m, n, p );
    return 0;
}