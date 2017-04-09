#include<bits/stdc++.h>
using namespace std;

//3 Partition Problem

int main()
{ 
    
    int n,a[100000],dp[1000][1000],sum,ans=0,i,j,b[100000],sum1=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
    cin>>a[i];
    sum=sum+a[i];
    }
    
    if(sum%3!=0)
    ans=0;
    
    else
    {
    
    
    for(i=0;i<=n;i++)
    dp[0][i]=1;
    
     for(i=1;i<=sum;i++)
     dp[i][0]=0;
     
         for(i=1;i<=sum;i++)
         {
             for(j=1;j<=n;j++)
             {
                  dp[i][j]=dp[i][j-1];
                 
                 if(a[j]<=i)
                 dp[i][j]=(dp[i][j] || dp[i-a[j]][j-1]);
                 
            }
         }
     
   int x,s[100000]; 
   memset(s,0,sizeof(s));
    int y=sum/3;
    while(y>0)
    { 
        for(j=1;j<=n;j++)
        {
            if(dp[y][j]==1)
            {
                x=j;
                break;
            }
        }
        s[x]=1;
        y=y-a[x];
    }
     


int k=0;
for(i=0;i<n;i++)
{
    if(s[i]==0)
    {
    b[k]=a[i];
    k++;
    sum1=sum1+b[k];
    }
}

int dp1[1000][1000];

 for(i=0;i<=k;i++)
    dp1[0][i]=1;
    
     for(i=1;i<=sum1;i++)
     dp1[i][0]=0;
     
         for(i=1;i<=sum1;i++)
         {
             for(j=1;j<=k;j++)
             {
                  dp1[i][j]=dp1[i][j-1];
                 
                 if(b[j]<=i)
                 dp1[i][j]=(dp1[i][j] || dp1[i-b[j]][j-1]);
                 
            }
         }
         
         if(dp1[sum1/2][k])
         ans=1;
}
if(ans==1)
cout<<"Yes";
else
cout<<"No";
         
return 0;
}

