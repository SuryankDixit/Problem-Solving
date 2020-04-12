class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<S || (sum+S)&1) return 0;
        
        sum = (sum+S)/2;
        vector<int> dp(sum+1,0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=sum;j>=nums[i];j--)
            {
                dp[j]+=dp[j-nums[i]];
            }
        }
        return dp[sum];
        
    }
        
};
