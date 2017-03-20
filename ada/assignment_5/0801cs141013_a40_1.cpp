/* nth Fibonacci Number using Bottom Up Dynamic Programming Approach
	Fibonacci Series used is : 0 1 1 2 3 5 8 13 ---- */

#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	if(n == 1)
		return 0;
	else if(n == 2)
		return 1;
	int a = 0, b=1, c;
	for(int i = 1; i <= n-2;i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
int main()
{
	int n;
	cin>>n;
	cout<<n<<" th fibonacci sequence is : "<<fib(n)<<endl;
	return 0;
}