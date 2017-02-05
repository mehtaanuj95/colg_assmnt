/*
@author : Anuj Bhai Mehta
Description : Bucket Sort
Date: Sunday, 5 Feburary 2017
*/
#include <bits/stdc++.h>
using namespace std;

void bucket(float a[], int n)
{
    vector<float> bucket[n];

    for(int i = 0; i < n;i++)
    {
        int val = a[i]*n;
        bucket[val].push_back(a[i]);
    }

    for(int i = 0; i <n;i++)
    {
        sort(bucket[i].begin(), bucket[i].end());
    }
    int count = 0;
    for(int i = 0; i < n;i++)
    {
        for(int j = 0; j < bucket[i].size(); j++)
        {
            a[count] = bucket[i][j];
            count++;
        }
    }
}
void printArray(float a[], int length)
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
		float a1[10], a2[100], a3[1000], a4[5000], a5[10000];
		for(int i = 0; i <10;i++)
		{
			if(i %2 == 0)
			{
				a1[i]= 0.1234;
			}
			else
			{
				a1[i] = 0.2345;
			}
		}

		for(int i = 0; i <100;i++)
		{
			if(i %2 == 0)
			{
				a2[i]= 0.1234;
			}
			else
			{
				a2[i] = 0.2345;
			}
		}
		for(int i = 0; i <1000;i++)
		{
			if(i %2 == 0)
			{
				a3[i]= 0.1234;
			}
			else
			{
				a3[i] = 0.2345;
			}
		}
		for(int i = 0; i <5000;i++)
		{
			if(i %2 == 0)
			{
				a4[i]= 0.1234;
			}
			else
			{
				a4[i] = 0.2345;
			}
		}
		for(int i = 0; i <10000;i++)
		{
			if(i %2 == 0)
			{
				a5[i]= 0.1234;
			}
			else
			{
				a5[i] = 0.2345;
			}
		}
		

		clock_t t;

		t = clock();
		bucket(a1, 10);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		bucket(a2, 100);
		t = clock() - t;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		bucket(a3, 1000);
		t = clock() - t;
		cout<<"Test Case 3__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		bucket(a4, 5000);
		t = clock() - t;
		cout<<"Test Case 4__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		bucket(a5, 10000);
		t = clock() - t;
		cout<<"Test Case 5__Size : 10000__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		float a[n];
		if(argc == 2)
		{
			for(int i = 0; i < n;i++)
			{
				cin>>a[i];
			}
			cout<<"Input Array : ";
			//printArray(a,n);
			bucket(a,n);
			cout<<"Sorted Array : ";
			printArray(a,n);
		}
		
	}
}
