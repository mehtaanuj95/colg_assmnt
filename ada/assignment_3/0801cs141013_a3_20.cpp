#include <bits/stdc++.h>
using namespace std;

void multiply(int a[][2], int m[][2])
{
	int x = a[0][0]*m[0][0] + a[0][1]*m[1][0];
	int y = a[0][0]*m[0][1] + a[0][1]*m[1][1];
	int z = a[1][0]*m[0][0] + a[1][1]*m[1][0];
	int p = a[1][0]*m[0][1] + a[1][1]*m[1][1];

	a[0][0] = x;
	a[0][1] = y;
	a[1][0] = z;
	a[1][1] = p;

}
void powerMatrix(int a[][2], int n)
{
	if(n == 0 || n == 1)
		return;
	int m[2][2]={{1,1},{1,0}};

	powerMatrix(a,n/2);
	multiply(a,a);

	if(n%2 != 0)
		multiply(a,m);
}
void fibonacci(int n)
{

	int a[2][2] = {{1,1},{1,0}};
	powerMatrix(a,n);
	cout<<n<<"th Fibonacci number : "<<a[0][0]<<endl;
}

int main(int argc, char* argv[])
{

	int n;

	if(argc == 1)
	{
		cout<<"Usage: ./a.out {n / test} {case}"<<endl;
		return 0;
	}
	if(strcmp(argv[1], "test") == 0)
	{
		cout<<"\nActivating Test Mode\n"<<endl;

		clock_t t;

		t = clock();
		fibonacci(5);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(15);
		t = clock() - t;
		cout<<"Test Case 1__Size : 15__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(25);
		t = clock() - t;
		cout<<"Test Case 1__Size : 25__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(35);
		t = clock() - t;
		cout<<"Test Case 1__Size : 35__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		fibonacci(50);
		t = clock() - t;
		cout<<"Test Case 1__Size : 50__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		if(argc == 2)
		{
			fibonacci(n-1);
		}
	}
}