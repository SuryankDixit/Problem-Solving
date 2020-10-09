
// Min Steps to One

#include <bits/stdc++.h>
using namespace std;


vector<int> dp;

int dfs(int n){
    
    if(n==1)
        return 0;
    
    int min1,min2,min3;
    min1=min2=min3 = INT_MAX;
    
    if(dp[n-1]!=-1){
        return dp[n];
    }
    
    if(n%2==0){
        min1 = dfs(n/2);
    }
    if(n%3==0){
        min2=dfs(n/3);
    }
    min3 = dfs(n-1);
    
    return dp[n-1] = min(min(min1,min2),min3)+1;
}

int main()
{
    int n;
    cin>>n;
    
    dp.resize(n,-1);
    dp[0]=0;
    int min_steps = dfs(n);
    cout<<min_steps;
    
    cout<<endl;
    for(auto x:dp)
        cout<<x<<" ";
    return 0;
}

