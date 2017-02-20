#include <bits/stdc++.h>
using namespace std;

void binary(int a[], int n, int data)
{
	int low = 0, high = n-1, mid1,mid2, flag = 0;
	while(low <= high)
	{
		mid1 = low + (high - low)/3;
		mid2 = mid1 + ((high - low)/3);

		if(data == a[low])
		{
			flag++;
			cout<<"Found at index : "<<low<<endl;
			break;
		}
		if(data == a[high])
		{
			flag++;
			cout<<"Found at index : "<<high<<endl;
			break;
		}

		if(data == a[mid1])
		{
			flag++;
			cout<<"Found at index : "<<mid1<<endl;
			break;
		}
		if(data == a[mid2])
		{
			flag++;
			cout<<"Found at index : "<<mid2<<endl;
			break;
		}
		if(data < a[mid1])
		{
			high = mid1 - 1;
		}
		else if(data > a[mid1] && data < a[mid2])
		{
			low = mid1 + 1;
			high = mid2 - 1;
			
		}
		else
		{
			low = mid2 + 1;
			
		}
	}
	if(flag == 0)
		cout<<"Not Found"<<endl;
	flag = 0;
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
		mt19937 mt(1729);
		int range = 2999999;
		set<int> myset1, myset2, myset3, myset4, myset5;
		set<int>::iterator it;
		uniform_int_distribution<int> dist1(0,range);
		for(int i = 0;i<10; i++)
		{
			myset1.insert(dist1(mt));
		}
		int counter = 0;
		for(it=myset1.begin(); it!= myset1.end(); it++)
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
		for(it=myset2.begin(); it!= myset2.end(); it++)
		{
			a2[counter] = *it;
			counter++;
		}

		uniform_int_distribution<int> dist3(0,range);
		for(int i = 0;i<1000; i++)
		{
			myset3.insert(dist3(mt));
		}
		counter = 0;
		for(it=myset3.begin(); it!= myset3.end(); it++)
		{
			a3[counter] = *it;
			counter++;
		}

		uniform_int_distribution<int> dist4(0,range);
		for(int i = 0;i<10000; i++)
		{
			myset4.insert(dist4(mt));
		}
		counter = 0;
		for(it=myset4.begin(); it!= myset4.end(); it++)
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
		for(it=myset5.begin(); it!= myset5.end(); it++)
		{
			a5[counter] = *it;
			counter++;
		}

		clock_t t;

		t = clock();
		//printArray(a1,10);
		binary(a1, 10, 1729);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		//printArray(a2,100);
		binary(a2, 100, 1729);
		t = clock() - t;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		binary(a3, 1000, 1729);
		t = clock() - t;
		cout<<"Test Case 3__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		binary(a5, 5000, 1452);
		t = clock() - t;
		cout<<"Test Case 4__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		binary(a4, 10000, 1729);
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
			int data;
			cout<<"Enter Data to be searched for"<<endl;
			cin>>data;
			binary(a,n,data);
		}
	}
}
