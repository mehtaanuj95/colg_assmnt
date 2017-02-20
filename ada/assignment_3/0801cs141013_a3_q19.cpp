#include <bits/stdc++.h>
using namespace std;

void maxdiff(int a[], int n)
{
	int max = a[1] - a[0], index1=0,index2=1;
	for(int i = 0; i < n-1; i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if((a[j] - a[i]) > max)
			{
				max = (a[j] - a[i]);
				index1 = i;
				index2 = j;
			}
		}
	}
	cout<<"The greatest forward difference is : "<<max<<" btw "<<index1<<" & "<<index2<<endl;
}
void printArray(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

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
		int a1[10], a2[100], a3[1000], a4[10000], a5[5000];
		mt19937 mt1(1729);
		mt19937 mt2(1730);
		mt19937 mt3(1731);
		mt19937 mt4(1732);
		mt19937 mt5(1733);
		int range = 2999999;
		uniform_int_distribution<int> dist1(0,range);
		for(int i = 0;i<10; i++)
		{
			//myset1.insert(dist1(mt));
			a1[i] = dist1(mt1);
		}
		
		//printArray(a1, 10);
		
		uniform_int_distribution<int> dist2(0,range);
		for(int i = 0;i<100; i++)
		{
			//myset1.insert(dist1(mt));
			a2[i] = dist2(mt2);
		}

		
		uniform_int_distribution<int> dist3(0,range);
		for(int i = 0;i<1000; i++)
		{
			//myset1.insert(dist1(mt));
			a3[i] = dist3(mt3);
		}

		uniform_int_distribution<int> dist4(0,range);
		for(int i = 0;i<5000; i++)
		{
			//myset1.insert(dist1(mt));
			a5[i] = dist4(mt4);
		}

		uniform_int_distribution<int> dist5(0,range);
		for(int i = 0;i<10000; i++)
		{
			//myset1.insert(dist1(mt));
			a4[i] = dist5(mt5);
		}

		clock_t t;

		t = clock();
		//printArray(a1,10);
		maxdiff(a1, 10);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		//printArray(a2,100);
		maxdiff(a2, 100);
		t = clock() - t;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		maxdiff(a3, 1000);
		t = clock() - t;
		cout<<"Test Case 3__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		maxdiff(a5, 5000);
		t = clock() - t;
		cout<<"Test Case 4__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		maxdiff(a4, 10000);
		t = clock() - t;
		cout<<"Test Case 5__Size : 10000__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		int a[n];
		if(argc == 2)
		{
			for(int i = 0; i < n;i++)
			{
				cin>>a[i];
			}
			cout<<"Input Array : ";
			printArray(a,n);
			maxdiff(a,n);
		}
	}
}