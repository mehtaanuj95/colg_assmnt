/*
@author : Anuj Bhai Mehta
Description : Custom Sort
Date: Saturday, 21 January 2017
Usage: g++ ass1_q3.cpp 
*/

#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n],w[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    
    multimap<int, int> num;
    multimap<int, int>::iterator it;
    //multimap<int, int>::iterator k;
    std::multimap<int,int>::reverse_iterator rit;
    std::multimap<int,int>::reverse_iterator k;
    for(int i=0;i<n;i++)
    {
        num.insert(make_pair(w[i],a[i]));
    }
    
    int m[n][2],counter=n-1;
    
    for(it=num.begin(); it!=num.end(); it++)
    {
        //cout<<(*it).first<< " -> "<<(*it).second<<endl;
        m[counter][0] = (*it).second;
        m[counter][1] = (*it).first; 
        counter--;
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<m[i][0] <<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<m[i][1] <<"  ";
    }
    cout<<endl;
    
    int temp;
    for(int i = 0; i < n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(m[j][1] == m[j+1][1])
            {
                if(m[j][0] < m[j+1][0])
                {
                    temp = m[j][0];
                    m[j][0] = m[j+1][0];
                    m[j+1][0] = temp;
                }
            }
        }
    }
    cout<<"Corrected array is "<<endl<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<m[i][0] <<"  ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<m[i][1] <<"  ";
    }
    cout<<endl;


    return 0;
}
