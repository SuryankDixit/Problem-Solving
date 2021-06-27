#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> val(n);
    vector<int> wt(n);
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>val[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(w+1,0));
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int j=0;j<=w;j++)
        dp[0][j]=0;
 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(j>=wt[i-1])
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]]+val[i-1]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    cout<<dp[n][w];
}
