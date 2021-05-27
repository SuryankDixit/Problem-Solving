class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        
       int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum<S || (sum+S)&1) return 0;
        
        int s1 = (sum+S)/2;      // s1+s2=sum ---(1)   s1-s2=S ---(2)
        int n=nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(j>=nums[i-1])
                   dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
                else
                  dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][s1];
        
        /*
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
        
        */
    }
        
};