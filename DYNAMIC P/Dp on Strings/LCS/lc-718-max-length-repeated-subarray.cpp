class Solution {
public:
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int dp[n1+1][n2+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};