#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    int n,w;
    cin>>n>>w;
    vector<int> val(n);
    vector<int> wt(n);
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
        cin>>val[i];
        sum+=val[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(sum+1,INT_MAX));
 
    // dp[1][val[0]]=wt[0];
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
        for(int j=1;j<=sum;j++)
        {
            if(val[i-1]<=j){
                dp[i][j] = min(dp[i-1][j], wt[i-1]+dp[i-1][j-val[i-1]]);
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int ans=0;
    for(int i=sum;i>=0;i--){
        if(dp[n][i]<=w){
            ans=i;
            break;
        }
    }
    cout<<ans;
}
