
#include <bits/stdc++.h>
using namespace std;


vector<int> dp;

int dfs(int n,vector<int> &coins){
    
    if(n==0){
        return 0;
    }
    
    if(dp[n-1]!=-1){
        return dp[n-1];
    }
    
    int Min = INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(n-coins[i]>=0){
            Min = min(Min, dfs(n-coins[i],coins));
        }
    }
    dp[n-1]=Min+1;
    return dp[n-1];
}

int main()
{
    int n;
    cin>>n;
    
    
    vector<int> coins{1,7,10};
    
    dp.resize(n,-1);
    // dp[0]=0;
    int min_coins = dfs(n,coins);
    cout<<min_coins;
    
    cout<<endl;
    for(auto x:dp)
        cout<<x<<" ";
    return 0;
}


