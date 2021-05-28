class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,n+1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=n;j++){
                if(i-j*j>=0){
                    dp[i] = min(dp[i],dp[i-j*j]+1);
                    // cout<<dp[i]<<" ";
                }
            }
        }
        return dp[n];
    }
};