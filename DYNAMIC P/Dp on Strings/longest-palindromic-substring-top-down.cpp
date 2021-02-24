class Solution {
public:
    int ans = 0;
    int solve(string &s,int i,int j,vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(i==j){
            dp[i][j]=1;
            return 1;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(s[i]==s[j]){
            int len = j-i-1;
            if(len == solve(s,i+1,j-1,dp))
               return dp[i][j] = len+2;
        }
        return dp[i][j] = max(solve(s,i+1,j,dp), solve(s,i,j-1,dp));
    }
    
    string longestPalindrome(string s) {
        int n = s.size();
        if(n==0 || n==1)
            return s;
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        solve(s,0,n-1,dp);
        int idx=-1;
        ans = dp[0][n-1];
        for(int i=0;i<n;i++){
            if(dp[0][i]==ans){
                idx=i;
                break;
            }
        }
        string res="";
        while(ans>0){
            res+=s[idx--];
            ans--;
        }
        return res;
    }
};