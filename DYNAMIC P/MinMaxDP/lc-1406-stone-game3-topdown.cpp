#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[50001][2];
    int n;
    
    int dfs(vector<int> &v, int i,int turn){
        if(i>=n)    return 0;
        
        if(dp[i][turn]!=-1)     return dp[i][turn];
        
        if(turn==0){
            int x = v[i] + dfs(v,i+1,1);
            int y=INT_MIN;int z = INT_MIN;
            if(i+1<n)   y = v[i]+v[i+1]+dfs(v,i+2,1);
            if(i+2<n)   z = v[i]+v[i+1]+v[i+2]+dfs(v,i+3,1);
            dp[i][turn] = max(x,max(y,z));
        }else{
            int x = -v[i] + dfs(v,i+1,0);
            int y=INT_MAX;int z = INT_MAX;
            if(i+1<n)   y = (-v[i]-v[i+1]+dfs(v,i+2,0));
            if(i+2<n)   z = (-v[i]-v[i+1]-v[i+2]+dfs(v,i+3,0));
            dp[i][turn] = min(x,min(y,z));
        }
        return dp[i][turn];
    }
    
    string stoneGameIII(vector<int>& v) {
        n = v.size();
        memset(dp,-1,sizeof(dp));
        int x = dfs(v,0,0);
        if(x>0) return "Alice";
        if(x<0) return "Bob";
        return "Tie";
    }
};