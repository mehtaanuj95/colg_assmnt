/* C implementation QuickSort */
#include <bits/stdc++.h>
using namespace std;
 
int flag = 0;
// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
void linearSearch(int a[], int len, int data)
{
    for(int i = 0; i< len;i++)
    {
        if(a[i] == data)
        {
            return;
        }
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high, int data)
{
    
    if (low <= high)
    {
        if(arr[low] == data)
        {    
            cout<<"Data found at "<<low<<" index"<<endl;
            flag = 1;
            return;
        } 
        if(arr[high] == data)
        {    
            cout<<"Data found at "<<high<<" index"<<endl;
            flag = 1;
            return;
        }  
        int pi = partition(arr, low, high);
        //cout<<pi<<" "<<arr[pi]<<endl;
        if(arr[pi] == data)
        {
            cout<<"data found at "<<pi<<" index"<<endl;
            flag = 1;
            return;
        }
        if(data > arr[pi])
        {   
            quickSort(arr, pi+1, high, data);
        }
        else
        {
            quickSort(arr, low, pi - 1, data);   
        }
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

        int dup1[10], dup2[100], dup3[1000], dup4[5000], dup5[10000];
        clock_t t;

        t = clock();
        for(int c = 0;c<10;c++)
            dup1[c] = a1[c];
        flag = 0;
        quickSort(a1, 0, n-1, a1[8]);       
        if(flag == 0)
        {
            cout<<"Element not found"<<endl;
        }
        t = clock() - t;
        cout<<"Test Case 1__Size __ MyAlgo: 10__Time (in ticks) : "<<t<<endl;
        
        t = clock();
        linearSearch(dup1, 9, dup1[8]);
        t = clock() - t;
        cout<<"Test Case 1__Size __ Linear Search: 10__Time (in ticks) : "<<t<<endl<<endl;
        //----------------------------------//
        t = clock();
        for(int c = 0;c<100;c++)
            dup2[c] = a2[c];
        flag = 0;
        quickSort(a2, 0, 99, a2[97]);       
        if(flag == 0)
        {
            cout<<"Element not found"<<endl;
        }
        t = clock() - t;
        cout<<"Test Case 1__Size __ MyAlgo: 100__Time (in ticks) : "<<t<<endl;
        
        t = clock();
        linearSearch(dup2, 100, dup2[97]);
        t = clock() - t;
        cout<<"Test Case 1__Size __ Linear Search: 100__Time (in ticks) : "<<t<<endl<<endl;
        //----------------------------------//
        t = clock();
        for(int c = 0;c<1000;c++)
            dup3[c] = a3[c];
        flag = 0;
        quickSort(a3, 0, 999, a3[995]);       
        if(flag == 0)
        {
            cout<<"Element not found"<<endl;
        }
        t = clock() - t;
        cout<<"Test Case 1__Size __ MyAlgo: 1000__Time (in ticks) : "<<t<<endl;
        
        t = clock();
        linearSearch(dup3, 1000, dup3[995]);
        t = clock() - t;
        cout<<"Test Case 1__Size __ Linear Search: 1000__Time (in ticks) : "<<t<<endl<<endl;
        //----------------------------------//
        t = clock();
        for(int c = 0;c<5000;c++)
            dup4[c] = a4[c];
        flag = 0;
        quickSort(a4, 0, 4999, a4[4900]);       
        if(flag == 0)
        {
            cout<<"Element not found"<<endl;
        }
        t = clock() - t;
        cout<<"Test Case 1__Size __ MyAlgo: 5000__Time (in ticks) : "<<t<<endl;
        
        t = clock();
        linearSearch(dup4, 5000, dup4[4900]);
        t = clock() - t;
        cout<<"Test Case 1__Size __ Linear Search: 5000__Time (in ticks) : "<<t<<endl<<endl;
        //-----------------------------------//
        t = clock();
        for(int c = 0;c<10000;c++)
            dup5[c] = a5[c];
        flag = 0;
        quickSort(a5, 0, 9999, a5[9900]);       
        if(flag == 0)
        {
            cout<<"Element not found"<<endl;
        }
        t = clock() - t;
        cout<<"Test Case 1__Size __ MyAlgo: 10000__Time (in ticks) : "<<t<<endl;
        
        t = clock();
        linearSearch(dup5, 10000, dup5[9900]);
        t = clock() - t;
        cout<<"Test Case 1__Size __ Linear Search: 10000__Time (in ticks) : "<<t<<endl<<endl;
        //-----------------------------------//
    }
    else
    {
        n = atoi(argv[1]);
        int a[n],eval;
        if(argc == 2)
        {
            for(int i = 0; i < n;i++)
                cin>>a[i];
            int dup[n];
            for(int i = 0; i < n;i++)
                dup[i] = a[i];

            cout<<"Enter element to be searched in array"<<endl;
            cin>>eval;
            cout<<"Input Array : ";
            printArray(a,n);
            quickSort(a, 0, n-1, eval);       
            if(flag == 0)
            {
                cout<<"Element not found"<<endl;
            }     
        }
    }
}
