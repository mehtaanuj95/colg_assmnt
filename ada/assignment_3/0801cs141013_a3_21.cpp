#include <bits/stdc++.h>
using namespace std;

void majority(int a[], int n)
{
	int counter=1, key;
	key=a[0];
	for(int i=1;i<n;i++)
	{
		if(counter == 0)
		{
			counter=1;
			key=a[i];
		}
		else
		{	
			if(a[i] == key)
				counter++;
			else
				counter--;
		}
	}
	if(counter > 0)
	{
		counter = 0;
		for(int i =0;i<n;i++)
		{
			if(key == a[i])
			{
				counter++;
			}
		}
		if(counter > n/2)
			cout<<"Yes : "<<key<<endl;
		else
			cout<<"No"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
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
		int a1[10],a2[100],a3[1000],a4[5000],a5[10000];
		a1[0]=1;a2[0]=1;a3[0]=1;a4[0]=1;a5[0]=1;
		a1[1]=1;a2[1]=1;a3[1]=1;a4[1]=1;a5[1]=1;

		for(int i=2;i<10;i++)
		{
			if(i%2==0)
				a1[i] = 1;
			else
				a1[i] = 5;
		}
		for(int i=2;i<100;i++)
		{
			if(i%2==0)
				a2[i] = 1;
			else
				a2[i] = 5;
		}
		for(int i=2;i<1000;i++)
		{
			if(i%2==0)
				a3[i] = 1;
			else
				a3[i] = 5;
		}
		for(int i=2;i<5000;i++)
		{
			if(i%2==0)
				a4[i] = 1;
			else
				a4[i] = 5;
		}
		for(int i=2;i<10000;i++)
		{
			if(i%2==0)
				a5[i] = 1;
			else
				a5[i] = 5;
		}
		clock_t t;

		t = clock();
		majority(a1,10);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		majority(a2,100);
		t = clock() - t;
		cout<<"Test Case 1__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		majority(a3,1000);
		t = clock() - t;
		cout<<"Test Case 1__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		majority(a4,5000);
		t = clock() - t;
		cout<<"Test Case 1__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		majority(a5,10000);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10000__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		if(argc == 2)
		{
			int a[n];
			for(int i = 0;i<n;i++)
			{
				cin>>a[i];
			}
			majority(a,n);
		}
	}
}