

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
       /* if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];*/
        
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        int maximum_coins= max_coins(nums,1,nums.size()-1,dp);
        return maximum_coins;
    }
    
    int max_coins(vector<int> nums,int i,int j,vector<vector<int>> &dp)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int Max=INT_MIN;
        for(int k=i;k<j;k++)
        {
            int left,right;
            
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else{
                left=max_coins(nums,i,k,dp);
                dp[i][k]=left;
            }
            
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else{
                right=max_coins(nums,k+1,j,dp);
                dp[k+1][j]=right;
            }
            int temp_ans=left+right+nums[i-1]*nums[k]*nums[j];
            //int temp_ans=max_coins(nums,i,k,dp)+max_coins(nums,k+1,j,dp)+nums[i-1]*nums[k]*nums[j];
            Max=max(temp_ans,Max);
        }
        dp[i][j]=Max;
        return dp[i][j];
    }
};
