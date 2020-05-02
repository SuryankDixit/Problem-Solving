// 96. Unique Binary Search Trees CATLAN NUMBER

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        if(n<2)
            return dp[n];
        for(int i=2;i<=n;i++)
            for(int j=1;j<=i;j++){
                dp[i]+=dp[j-1]*dp[i-j];
            }
        return dp[n];
    }
};
