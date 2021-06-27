class Solution {
public:
    int n;
    vector<int> dp;
    int dfs(int idx,vector<int> &v){
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int sum=0;
        int element=v[idx];
        int nextIdx=idx;
        while(nextIdx<n && v[nextIdx]==element){
            sum+=element;
            nextIdx++;
        }
        int k = nextIdx;
        while(nextIdx<n && v[nextIdx]==element+1)
            nextIdx++;
        
        int ans = max(sum+dfs(nextIdx,v),dfs(k,v));
        return dp[idx] = ans;
    }
    
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        n=nums.size();
        dp.resize(n,-1);
        return dfs(0,nums);
    }
};
