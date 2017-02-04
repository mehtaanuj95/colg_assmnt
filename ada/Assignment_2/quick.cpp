/*
@author : Anuj Bhai Mehta
Description : Quick Sort
Date: Saturday, 4 Feburary 2017
*/
#include <bits/stdc++.h>
using namespace std;

int swap_counter =0, comp_counter = 0;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    
    int i = (low - 1); 
 
    for (int j = low; j <= high- 1; j++)
    {
    	comp_counter++;
        if (arr[j] <= pivot)
        {
            i++;
            swap_counter++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
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
		for(int i = 0;i<1000; i++)
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
		for(int i = 0;i<10000; i++)
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
		quickSort(a1, 0, 9);
		t = clock() - t;
		cout<<"No. of swaps: "<<swap_counter<<endl;
		cout<<"No. of comparison: "<<comp_counter<<endl;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		swap_counter =0;
		comp_counter = 0;
		t = clock();
		quickSort(a2, 0,99);
		t = clock() - t;
		cout<<"No. of swaps: "<<swap_counter<<endl;
		cout<<"No. of comparison: "<<comp_counter<<endl;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		swap_counter =0;
		comp_counter = 0;
		t = clock();
		quickSort(a3,0, 999);
		t = clock() - t;
		cout<<"No. of swaps: "<<swap_counter<<endl;
		cout<<"No. of comparison: "<<comp_counter<<endl;
		cout<<"Test Case 3__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		swap_counter =0;
		comp_counter = 0;
		t = clock();
		quickSort(a5,0, 4999);
		t = clock() - t;
		cout<<"No. of swaps: "<<swap_counter<<endl;
		cout<<"No. of comparison: "<<comp_counter<<endl;
		cout<<"Test Case 4__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		swap_counter =0;
		comp_counter = 0;
		t = clock();
		quickSort(a4,0, 9999);
		t = clock() - t;
		cout<<"No. of swaps: "<<swap_counter<<endl;
		cout<<"No. of comparison: "<<comp_counter<<endl;
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
			quickSort(a,0, n-1);
			cout<<"Sorted Array : ";
			printArray(a,n);
			cout<<"No. of swaps: "<<swap_counter<<endl;
			cout<<"No. of comparison: "<<comp_counter<<endl;
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
				quickSort(a,0,n-1);
				cout<<"Sorted Array : ";
				printArray(a,n);
				cout<<"No. of swaps: "<<swap_counter<<endl;
				cout<<"No. of comparison: "<<comp_counter<<endl;
			}
			else if(strcmp(argv[2], "worst") == 0)
			{
				for(int i = 0; i < n;i++)
				{
					a[i] = n-i;
				}
				cout<<"Input Array : ";
				printArray(a,n);
				quickSort(a,0,n-1);
				cout<<"Sorted Array : ";
				printArray(a,n);
				cout<<"No. of swaps: "<<swap_counter<<endl;
				cout<<"No. of comparison: "<<comp_counter<<endl;
			}
			else
			{
				cout<<"Bad Case Usage: {best} / {worst}"<<endl;
				return 0; 
			}
		}

	}

}
