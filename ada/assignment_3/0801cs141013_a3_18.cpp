#include <bits/stdc++.h>
using namespace std;

void mindistance(int a[][2], int n)
{
	int min,dis,x1,x2,y1,y2;
	min = abs(a[0][0] - a[1][0]) + abs(a[0][1] - a[1][1]);
	x1 = a[0][0];	y1 = a[0][1];
	x2 = a[1][0]; 	y2 = a[1][1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i != j)
			{
				dis = abs(a[i][0] - a[j][0]) + abs(a[i][1] - a[j][1]);
				if(dis < min)
				{
					min = dis;
					x1 = a[i][0];
					x2 = a[j][0];
					y1 = a[i][1];
					y2 = a[j][1];
				}
			}
		}
	}
	cout<<"(x1,y1) : "<<x1<<","<<y1<<endl;
	cout<<"(x2,y2) : "<<x2<<","<<y2<<endl;
}
void printArray(int a[][2], int length)
{
	for(int i = 0; i < length; i++)
	{
		cout<<a[i][0]<< " "<<a[i][1]<<endl;
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
		int a1[10][2], a2[100][2], a3[1000][2], a4[10000][2], a5[5000][2];
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
			a1[i][0] = dist1(mt1);
			a1[i][1] = dist1(mt1);
		}		
		uniform_int_distribution<int> dist2(0,range);
		for(int i = 0;i<100; i++)
		{
			//myset1.insert(dist1(mt));
			a2[i][0] = dist2(mt2);
			a2[i][1] = dist2(mt2);
		}

		uniform_int_distribution<int> dist3(0,range);
		for(int i = 0;i<1000; i++)
		{
			//myset1.insert(dist1(mt));
			a3[i][0] = dist3(mt3);
			a3[i][1] = dist3(mt3);
		}

		uniform_int_distribution<int> dist4(0,range);
		for(int i = 0;i<5000; i++)
		{
			//myset1.insert(dist1(mt));
			a5[i][0] = dist4(mt4);
			a5[i][1] = dist4(mt4);
		}

		uniform_int_distribution<int> dist5(0,range);
		for(int i = 0;i<10000; i++)
		{
			//myset1.insert(dist1(mt));
			a4[i][0] = dist5(mt5);
			a4[i][1] = dist5(mt5);
		}

		clock_t t;

		t = clock();
		//printArray(a1,10);
		mindistance(a1, 10);
		t = clock() - t;
		cout<<"Test Case 1__Size : 10__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		//printArray(a2,100);
		mindistance(a2, 100);
		t = clock() - t;
		cout<<"Test Case 2__Size : 100__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		mindistance(a3, 1000);
		t = clock() - t;
		cout<<"Test Case 3__Size : 1000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		mindistance(a5, 5000);
		t = clock() - t;
		cout<<"Test Case 4__Size : 5000__Time (in ticks) : "<<t<<endl<<endl;

		t = clock();
		mindistance(a4, 10000);
		t = clock() - t;
		cout<<"Test Case 5__Size : 10000__Time (in ticks) : "<<t<<endl<<endl;

	}
	else
	{
		n = atoi(argv[1]);
		int a[n][2];
		if(argc == 2)
		{
			cout<<"Please enter n pair of points"<<endl;
			for(int i = 0; i < n;i++)
			{
				cin>>a[i][0];
				cin>>a[i][1];
			}
			mindistance(a,n);
		}
	}
}