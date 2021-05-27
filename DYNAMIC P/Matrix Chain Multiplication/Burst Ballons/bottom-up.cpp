class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size()-1;
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){       // iteration equal to number of matrices
            for(int left=0;left<n-i;left++){
                int right = left+i;
                for(int k=left;k<right;k++){
                    dp[left][right] = 
                        max(dp[left][k]+dp[k+1][right]+nums[left]*nums[k+1]*nums[right+1],dp[left][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
