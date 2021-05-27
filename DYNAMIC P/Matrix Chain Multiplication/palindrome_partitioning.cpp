class Solution {
public:
    int minCut(string s) {
        std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
        vector<
            vector<int>> is_palindrome(s.size(), vector<int>(s.size()));
        isPalindrome(s,is_palindrome);
        int cuts=min_cuts(s,0,s.size()-1,dp,is_palindrome);
        return cuts;
    }
    
    int min_cuts(string s,int i,int j,vector<vector<int>> &dp,vector<vector<int>> &is_palindrome)
    {
        if(i>=j || is_palindrome[i][j])
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int Min=INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int left,right;
            if(dp[i][k]!=-1)
                left=dp[i][k];
            else{
                left=min_cuts(s,i,k,dp,is_palindrome);
                dp[i][k]=left;
            }
            
            if(dp[k+1][j]!=-1)
                right=dp[k+1][j];
            else{
                right=min_cuts(s,k+1,j,dp,is_palindrome);
                dp[k+1][j]=right;
            }
            //int temp_ans=min_cuts(s,i,k,dp)+min_cuts(s,k+1,j,dp)+1;
            int temp_ans=left+right+1;
            Min=min(temp_ans,Min);
        }
        dp[i][j]=Min;
        return dp[i][j];
    }
    
    void isPalindrome(string s,vector<vector<int>> &is_palindrome)
    {
        for (int i = 0; i < s.size(); ++i) {
            is_palindrome[i][i] = true;
            for (int j = 0; j < i; ++j) {
                if (s[i] != s[j]) continue;
                if (i == j + 1 or is_palindrome[i - 1][j + 1]) 
                    is_palindrome[i][j] = is_palindrome[j][i] = true;
            }
        }
    }
};
