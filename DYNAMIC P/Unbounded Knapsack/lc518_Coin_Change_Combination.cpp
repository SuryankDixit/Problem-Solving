class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<int> dp(amount+1,0);
        dp[0]=1;
        
        
        // Outer loop is coins array because this will stop permutations from generating.
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<dp.size();j++){
                
                dp[j] += dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
