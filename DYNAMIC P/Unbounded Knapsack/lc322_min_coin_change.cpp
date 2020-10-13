class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        
        for(int i=0;i<dp.size();i++){
            for(auto coin:coins){
                if(i-coin>=0){
                    dp[i] = min(dp[i],dp[i-coin]+1);
                }
            }
        }
        if(dp[amount]!=amount+1)
            return dp[amount];
        return -1;
    }
};
