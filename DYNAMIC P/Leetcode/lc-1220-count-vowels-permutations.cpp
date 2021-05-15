#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> m{{1},{0,2},{0,1,3,4},{2,4},{0}};
    int dp[200005][5];
    const int mod = 1e9+7;
    
    int dfs(int i,int n){
        if(n<0)
            return 0;
        if(n==1)
            return 1;
        
        if(dp[n][i]!=-1)
            return dp[n][i];
        int cnt=0;
        for(auto x:m[i]){
            cnt+=dfs(x,n-1)%mod;
            cnt=cnt%mod;
        }
        return dp[n][i] = cnt;
    }
    
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<5;i++){
            ans+=dfs(i,n)%mod;
            ans=ans%mod;
        }
        return ans;
    }
};



//Bottom up
class Solution {
public:
    vector<vector<int>> m{{1},{0,2},{0,1,3,4},{2,4},{0}};
    int dp[200005][5];
    const int mod = 1e9+7;
    
    int countVowelPermutation(int n) {
        if(n==1)
            return 5;
        
        int ans=0;
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<5;i++)
            dp[0][i]=1;
        
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][1];    dp[i][0]=dp[i][0]%mod;
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;       dp[i][1]=dp[i][1]%mod;
            dp[i][2]=((((dp[i-1][1]%mod+dp[i-1][0]%mod)%mod+dp[i-1][3]%mod)%mod+dp[i-1][4]%mod)%mod)%mod ;        dp[i][2]=dp[i][2]%mod;
            dp[i][3]=(dp[i-1][2]+dp[i-1][4])%mod;       dp[i][3]=dp[i][3]%mod;
            dp[i][4]=(dp[i-1][0])%mod;          dp[i][4]=dp[i][4]%mod;
        }
        for(int i=0;i<5;i++)
            ans = (ans+dp[n-1][i])%mod;
        return ans;
    }
};