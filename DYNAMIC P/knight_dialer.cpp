//935. Knight Dialer leetcode
int knightDialer(int N) {
        
        vector<vector<long> > dp(N+1,vector<long>(10,0));
        for(int i=0;i<=9;i++)
            dp[1][i]=1;
        
        for(int i=2;i<=N;i++)
        {
            dp[i][0] = (dp[i-1][4] + dp[i-1][6])%1000000007;
            dp[i][1] = (dp[i-1][6] + dp[i-1][8])%1000000007;
            dp[i][2] = (dp[i-1][7] + dp[i-1][9])%1000000007;
            dp[i][3] = (dp[i-1][4] + dp[i-1][8])%1000000007;
            dp[i][4] = (dp[i-1][0] + dp[i-1][3] + dp[i-1][9])%1000000007;
            dp[i][6] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][7])%1000000007;
            dp[i][7] = (dp[i-1][2] + dp[i-1][6])%1000000007;
            dp[i][8] = (dp[i-1][1] + dp[i-1][3])%1000000007;
            dp[i][9] = (dp[i-1][2] + dp[i-1][4])%1000000007;
        }
        long ans=0;
        for(int i=0;i<=9;i++)
            ans=(ans%1000000007+dp[N][i]%1000000007)%1000000007;
        return ans;
    }
