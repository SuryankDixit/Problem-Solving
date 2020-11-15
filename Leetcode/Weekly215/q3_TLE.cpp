class Solution {
public:
    int n;
    int solve(vector<int>& nums,vector<vector<int>> &dp,int l,int r,int x){
        if(l>r || x<0)
            return -1;
        if(dp[l][r]!=0)
            return dp[l][r];
        if(x-nums[l]==0 || x-nums[r]==0){
            dp[l][r]=1;
            return 1;
        }
        int left = solve(nums,dp,l+1,r,x-nums[l]);
        int right= solve(nums,dp,l,r-1,x-nums[r]);
        if(left==-1 && right==-1){
            dp[l][r]=-1;
            return -1;
        }
        if(left==-1 || right==-1){
            if(left==-1)
                dp[l][r]=1+right;
            else
                dp[l][r]=1+left;
            return dp[l][r];
        }
        dp[l][r]=1+min(left,right);
        return dp[l][r];
    }

    int minOperations(vector<int>& nums, int x) {
        n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        return solve(nums,dp,0,n-1,x);
    }
};
