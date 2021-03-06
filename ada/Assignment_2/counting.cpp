/*
@author : Anuj Bhai Mehta
Description : Counting Sort
Date: Saturday, 4 Feburary 2017
*/
#include <bits/stdc++.h>
using namespace std;

void countingSort(int a[], int n, int b[])
{
	int len = 100001, val=0, index = 0;
	int countarray[100001]={0};
	//int b[n+1];
	//making count array
	for(int i = 0; i < n; i++)
	{
		val = a[i];
		countarray[val]++;
	}
	//modify count array to store sum
	for(int i = 1; i < len;i++)
	{
		countarray[i] = countarray[i-1] + countarray[i];
	}
	//search for original value in hash and place it in new array after decrement
	for(int i = 0; i < n; i++)
	{
		val = a[i];
		index = countarray[val];
		b[index] = val;
		countarray[val]--;
	}
	//print array
 	/*for(int i = 1; i < n+1;i++)
	cout<<b[i]<<" ";
	cout<<endl;*/
    cout<<"No. of swaps: 0"<<endl;
    cout<<"No. of comparison: 0"<<endl;
}
 
void printArray(int a[], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}
void printArray(int a[], int length, int index)
{
	for(int i = index; i < length; i++)
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
		int a1[10], a2[100], a3[500], a4[1000], a5[5000];
		int b1[11], b2[101], b3[501], b4[1001], b5[5001];
		mt19937 mt(1729);
		int range = 100001;
		set<int> myset1, myset2, myset3, myset4, myset5;
		set<int>::reverse_iterator it;
		uniform_int_distribution<int> dist1(0,range);
		for(int i = 0;i<10; i++)
		{
			myset1.insert(dist1(mt));
		}
		int counter = 0;
		for(it=myset1.rbegin(); it!= myset1.rend(); it++)
		{
			a1[counter] = *it;
			counter++;
		}
		//printArray(a1, 10);
		uniform_int_distribution<int> dist2(0,range);
		for(int i = 0;i<100; i++)
		{
			myset2.insert(dist2(mt));
		}
		counter = 0;
		for(it=myset2.rbegin(); it!= myset2.rend(); it++)
		{
			a2[counter] = *it;
			counter++;
		}

		uniform_int_distribution<int> dist3(0,range);
		for(int i = 0;i<500; i++)
		{
			myset3.insert(dist3(mt));
		}
		counter = 0;
		for(it=myset3.rbegin(); it!= myset3.rend(); it++)
		{
			a3[counter] = *it;
			counter++;
		}

		uniform_int_distribution<int> dist4(0,range);
		for(int i = 0;i<1000; i++)
		{
			myset4.insert(dist4(mt));
		}
		counter = 0;
		for(it=myset4.rbegin(); it!= myset4.rend(); it++)
		{
			a4[counter] = *it;
			counter++;
		}

		uniform_int_distribution<int> dist5(0,range);
		for(int i = 0;i<5000; i++)
		{
			myset5.insert(dist5(mt));
		}
		counter = 0;
		for(it=myset5.rbegin(); it!= myset5.rend(); it++)
		{
			a5[counter] = *it;
			counter++;
		}

		clock_t t;

		t = clock();
		countingSort(a1,10,b1);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		countingSort(a2,100,b2);
		t = clock() - t;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		countingSort(a3,500,b3);
		t = clock() - t;
		cout<<"Test Case 3__Size : 500__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		countingSort(a4,1000,b4);
		t = clock() - t;
		cout<<"Test Case 4__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		countingSort(a5,5000,b5);
		t = clock() - t;
		cout<<"Test Case 5__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		int a[n];
		int b[n+1];
		if(argc == 2)
		{
			for(int i = 0; i < n;i++)
			{
				cin>>a[i];
			}
			cout<<"Input Array : ";
			printArray(a,n);
			countingSort(a,n,b);
			cout<<"Sorted Array : ";
			printArray(b,n+1,1);
		}
		else if(argc == 3)
		{
			if(strcmp(argv[2], "best") == 0)
			{
				for(int i = 0; i < n;i++)
				{
					a[i] = i+1;
				}
				cout<<"Input Array : ";
				printArray(a,n);
				countingSort(a,n,b);
				cout<<"Sorted Array : ";
				printArray(b,n+1,1);
			}
			else if(strcmp(argv[2], "worst") == 0)
			{
				for(int i = 0; i < n;i++)
				{
					a[i] = n-i;
				}
				cout<<"Input Array : ";
				printArray(a,n);
				countingSort(a,n,b);
				cout<<"Sorted Array : ";
				printArray(b,n+1,1);
			}
			else
			{
				cout<<"Bad Case Usage: {best} / {worst}"<<endl;
				return 0; 
			}
		}

	}

}
