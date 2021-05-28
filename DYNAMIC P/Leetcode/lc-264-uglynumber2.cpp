class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        int t2,t3,t5;
        t2=t3=t5=0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i] = min(dp[t2]*2 , min(dp[t3]*3, dp[t5]*5));
            if(dp[i] == dp[t2]*2)
                t2++;
            if(dp[i] == dp[t3]*3)
                t3++;
            if(dp[i] == dp[t5]*5)
                t5++;
        }
        return dp[n-1];
    }
};