#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[]={0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    int n=sizeof(arr)/sizeof(int);
    int dp[16];
    int parent[16]={0};
    
    for(int i=0;i<n;i++)
        dp[i]=1;
        
    for(int j=1;j<n;j++)
    {
        for(int i=0;i<j;i++)
        {
            if(arr[j]>arr[i] && dp[j]<dp[i]+1)
            {
                dp[j]=dp[i]+1;
                parent[j]=arr[i];
            }
        }
    }
    int max=0;
    int index=0;
    for(int i=0;i<n;i++)
    {
        if(max<dp[i])
        {
            max=dp[i];
            index=i;
        }
    }
    cout<<"Length of the LIS: "<<max<<endl;
    cout<<"And the subsequence is :"<<endl;
    while(max)
    {
        cout<<arr[index]<<"<-";
        index=parent[index];
        max--;
    }
    
    return 0;
}
