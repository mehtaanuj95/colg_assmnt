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
 
/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
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
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int arr[], int low, int high, int data)
{
    
    if (low < high)
    {
        int pi = partition(arr, low, high);
        cout<<pi<<" "<<arr[pi]<<endl;
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
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int a[10];
    int n = 10;
    for(int i = 0;i<n;i++)
    {
        for(int j = 0; j < 10;j++)
            a[j] = 9-j;

        quickSort(a, 0, n-1, a[i]);
        if(flag == 0)
        {
            cout<<"Element not found"<<endl<<endl;
        }
    }
    
    
    return 0;
}