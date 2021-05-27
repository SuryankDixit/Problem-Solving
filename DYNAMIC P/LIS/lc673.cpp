/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.

 

Example 1:

Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
Example 2:

Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.

*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> cnt(n,1);
        
        int Max = INT_MIN;
        int idx=-1;
        int count=0;
        int ans=0;
        
        if(n==1)
            return 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[i]<=dp[j]+1){
                    if(dp[i]<dp[j]+1){
                        cnt[i]=cnt[j];
                    }else if(dp[i]==dp[j]+1){
                        cnt[i]+=cnt[j];
                    }
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            Max= max(dp[i],Max);
        }
        for(int i=0;i<n;i++){
            if(Max==dp[i])
                ans+=cnt[i];
        }
        return ans;
    }
};
