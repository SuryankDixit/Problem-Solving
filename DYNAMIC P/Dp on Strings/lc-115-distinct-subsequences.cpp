class Solution {
public:
    typedef unsigned long long int ll;
    int numDistinct(string s, string t) {
        int n1=s.size()+1;
        int n2=t.size()+1;
        if(n1<n2)
            return 0;
        
        vector<vector<ll>> dp(n2,vector<ll>(n1,0));
        
        // "" "" have 1 subsequence in common;
        for(int i=0;i<n1;i++)
            dp[0][i]=1;
        
        for(int i=1;i<n2;i++){
            for(int j=1;j<n1;j++){
                if(s[j-1] != t[i-1])
                    dp[i][j]=dp[i][j-1];
                else{
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                } 
            }
        }
        return dp[n2-1][n1-1];
    }
};