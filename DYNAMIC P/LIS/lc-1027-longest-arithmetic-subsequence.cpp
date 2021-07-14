class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        int ans =2;
        // dp[idx][diff] = lengrh of subsequence of diff upto idx
        vector<vector<int>> dp(n,vector<int>(1505,0));
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int diff = nums[j]-nums[i] + 999;
                dp[j][diff] = max(2,dp[i][diff]+1);
                ans = max(ans,dp[j][diff]);
            }
        }
        return ans;
    }
};