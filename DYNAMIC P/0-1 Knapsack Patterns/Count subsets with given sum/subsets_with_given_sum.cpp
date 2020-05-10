
/*
Input: arr[] = {1, 2, 3, 3}, X = 6
Output: 3
All the possible subsets are {1, 2, 3},
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1
Output: 4
*/

#include <bits/stdc++.h>

using namespace std;

int find_subsets_with_given_sum(vector<int> &v,int sum)
{
    int n=v.size();
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            if(i==0)
                dp[i][j]=0;
            if(j==0)
                dp[i][j]=1;
            
            if(i!=0 && j!=0)
            {
                if(j>=v[i-1])
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-v[i-1]];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sum;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin>>n;     //size of array;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
        cin>>v[i];
    
    int sum;
    cin>>sum;
    int count=find_subsets_with_given_sum(v,sum);
    cout<<count<<endl;
    return 0;
}
