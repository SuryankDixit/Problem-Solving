#include <bits/stdc++.h>

using namespace std;


int dfs_knapsack(int n, int w,vector<int> &val, vector<int> &wt,vector<vector<int>> &dp){

    // cout<<"("<<n-1<<","<<w<<")"<<endl;
    if(n==0|| w==0)
        return 0;

    if(dp[n-1][w-1]!=-1){
        return dp[n-1][w-1];
    }
    
    if(w>=wt[n-1]){
        return dp[n-1][w-1] = max(dfs_knapsack(n-1,w-wt[n-1],val,wt,dp)+val[n-1],dfs_knapsack(n-1,w
            ,val,wt,dp));
    }else{
        return dp[n-1][w-1] = dfs_knapsack(n-1,w,val,wt,dp);
    }
}


int main() {
    

     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;
    vector<int> wt(n);
    vector<int> val(n);
    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];
    int W;
    cin>>W;

    vector<vector<int>> dp(n,vector<int>(W,-1));

    cout<<dfs_knapsack(n,W,val,wt,dp);
}

