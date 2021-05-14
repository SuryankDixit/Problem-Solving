class Solution {
public:
    vector<int> dp;
    int dfs(vector<int> &c,int idx){
        if(idx<0)
            return 0;
        if(idx<=1)
            return c[idx];
        if(dp[idx]!=-1)
            return dp[idx];
        
        return dp[idx]=c[idx]+min(dfs(c,idx-1),dfs(c,idx-2));
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2)
            return min(cost[0],cost[1]);
        
        dp.resize(n,-1);
        return min(dfs(cost,n-1),dfs(cost,n-2));
   }
};