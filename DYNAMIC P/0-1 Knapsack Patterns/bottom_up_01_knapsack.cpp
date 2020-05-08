
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &val, vector<int> &wt, int n,int w,vector<vector<int>> &dp)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=w;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,w;
	    cin>>n>>w;
	    vector<int> val(n);
	    vector<int> wt(n);
	    for(int i=0;i<n;i++)
	        cin>>val[i];
	    for(int i=0;i<n;i++)
	        cin>>wt[i];
	    
	    vector<vector<int>> dp(n+1,vector<int>(w+1,0));
	    
	    int max_profit=knapsack(val,wt,n,w,dp);
	    cout<<max_profit<<endl;
	}
	return 0;
}