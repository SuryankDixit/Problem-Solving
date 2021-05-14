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


//bottom up
class Solution {
public:

    int minCostClimbingStairs(vector<int>& c) {
        int n = c.size();
        if(n==2)
            return min(c[0],c[1]);
        
        vector<int> dp(n,-1);
        for(int i=0;i<n;i++){
            if(i<2)
                dp[i]=c[i];
            else
                dp[i]=c[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
   }
};