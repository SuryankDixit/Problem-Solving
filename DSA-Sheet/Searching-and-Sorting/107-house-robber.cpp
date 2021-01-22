
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    // Your code here
    if(n==1)
        return arr[0];
    vector<ll> dp(n,0);
    dp[0]=arr[0];
    dp[1]=max(arr[0],arr[1]);
    for(ll i=2;i<n;i++){
        dp[i]=max(dp[i-1],arr[i]+dp[i-2]);
    }
    return max(dp[n-1],dp[n-2]);
}