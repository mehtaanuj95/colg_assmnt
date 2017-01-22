/*
@author : Anuj Bhai Mehta
Description : 
Date: Saturday, 21 January 2017
Usage: g++ ass1_q8.cpp
*/

#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> myset;
    set<int>::iterator it;
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0];
        a[i][1] = i;
        myset.insert(a[i][0]);
    }

    int val;
    int freq[n][2],counter=0,index=n-1,val_count=0;
    // generate frequency array
    for(it=myset.begin(); it!=myset.end(); it++)
    {
        val=*it;
        for(int i=n-1;i>=0;i--)
        {
            if(a[i][0]==val)
            {
                index=i;
                val_count++;
            }
        }
        freq[counter][0]=index;
        freq[counter][1]=val_count;
        index=val_count=0;
        counter++;
    }

    int temp0,temp1;
    for(int i=0;i<counter;i++)
    {
        for(int j=0;j<counter-1;j++) 
        {
            if(freq[j][1] < freq[j+1][1])
            {
                temp0 = freq[j][0];
                freq[j][0] = freq[j+1][0];
                freq[j+1][0] = temp0;

                temp1=freq[j][1];
                freq[j][1] = freq[j+1][1];
                freq[j+1][1] = temp1;
            }
        }
    }
    int j;
    for(int i=0;i<counter;i++)
    {
        for(j=0;j<counter-1;j++)
        {
           if(freq[j][1] == freq[j+1][1])
            {
                if(freq[j][0] > freq[j+1][0])
                {
                    temp0 = freq[j][0];
                    freq[j][0] = freq[j+1][0];
                    freq[j+1][0] = temp0;    
                }
            } 
        }  
    }
    cout<<"Array according to frequency is"<<endl;
    for(int i=0;i<counter;i++)
    {
        val = freq[i][0];
        /* cout<<a[val][0]<<"  "<<freq[i][1]<<endl;*/
        cout<<a[val][0]<<"  ";
    }
	cout<<endl;
    return 0;
}