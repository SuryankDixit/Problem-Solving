#include <bits/stdc++.h>

using namespace std;

int total_sum=0;

int min_subset_sum_difference(int n,vector<int> &nums,int sum,vector<vector<int>> &dp){

    // cout<<n<<" "<<sum<<endl;

    if(n==0){
        return abs(total_sum-2*sum);
    }

    if(dp[n-1][sum]!=-1){
        return dp[n-1][sum];
    }

    int min1 = min_subset_sum_difference(n-1,nums,sum+nums[n-1],dp);
    int min2 = min_subset_sum_difference(n-1,nums,sum,dp);

    return dp[n-1][sum] = min(min1,min2);
}


int main() {
    

     #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
        total_sum += nums[i];
    }
    // cout<<total_sum;
    vector<vector<int>> dp(n,vector<int>(total_sum+1,-1));

    cout<<min_subset_sum_difference(n,nums,0,dp);
}
