#include <bits/stdc++.h>

using namespace std;


int dfs_subsetSum(int n,vector<int> &nums,int sum,vector<vector<int>> &dp){

    // cout<<sum<<endl;

   if(sum==0)
    return 1;

    if(n==0)
        return 0;

    if(dp[n-1][sum-1]!=-1)
        return dp[n-1][sum-1];

    if(nums[n-1] <= sum){
        return dp[n-1][sum-1] = (dfs_subsetSum(n-1,nums,sum-nums[n-1],dp) + dfs_subsetSum(n-1,nums,sum,dp) );
    }else{
        return dp[n-1][sum-1] = dfs_subsetSum(n-1,nums,sum,dp);
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

    for(int i=0;i<n;i++)
        cin>>wt[i];
    int sum;
    cin>>sum;

    vector<vector<int>> dp(n,vector<int>(sum,-1));

    cout<<dfs_subsetSum(n,wt,sum,dp);
}


// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
// Output: True   1
// There is a subset (4, 5) with sum 9.

// Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
// Output: False 0
// There is no subset that add up to 30.
