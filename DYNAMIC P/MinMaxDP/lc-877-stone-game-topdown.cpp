#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1005][1005];
    
    int f(int l, int r, vector <int> &piles) {
        if(l>r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        int ifleft = piles[l] + min(f(l+2, r, piles), f(l+1, r-1, piles));
        int ifright = piles[r] + min(f(l+1, r-1, piles), f(l, r-2, piles));
        
        return dp[l][r] = max(ifleft, ifright);
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        int alex = f(l, r, piles);
        int sum = 0;
        for(int i=0;i<piles.size();i++) sum += piles[i];

        return alex > (sum - alex);
    }
};


class Solution {
public:
    int dp[501][501][2];
    
    int dfs(int l, int r,int turn,vector <int> &v) {
        if(l>=r) return 0;
        
        if(dp[l][r][turn] != -1) return dp[l][r][turn];
        
        if(turn==0){
            dp[l][r][turn] = max((v[l]+dfs(l+1,r,1-turn,v)),(v[r]+dfs(l,r-1,1-turn,v)));
        }else{
            dp[l][r][turn] = min((-v[l]+dfs(l+1,r,1-turn,v)),(-v[r]+dfs(l,r-1,1-turn,v)));
        }
        return dp[l][r][turn];
    }
    bool stoneGame(vector<int>& piles) {
        int l = 0, r = piles.size()-1;
        memset(dp, -1, sizeof(dp));
        return (dfs(l,r,0,piles)>=0);
    }
};