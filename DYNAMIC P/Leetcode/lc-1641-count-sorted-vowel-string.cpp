#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        if(n==1)
            return 5;
        int dp[50][5];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<5;i++)
            dp[0][i]=1;
        for(int i=0;i<n-1;i++){
            dp[i+1][0] = dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4];
            dp[i+1][1] = dp[i][1]+dp[i][2]+dp[i][3]+dp[i][4];
            dp[i+1][2] = dp[i][2]+dp[i][3]+dp[i][4];
            dp[i+1][3] = dp[i][3]+dp[i][4];
            dp[i+1][4] = dp[i][4];
        }
        ans = dp[n-1][0]+dp[n-1][1]+dp[n-1][2]+dp[n-1][3]+dp[n-1][4];
        return ans;
    }
};