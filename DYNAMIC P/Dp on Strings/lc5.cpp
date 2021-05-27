/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        if(n==0 || n==1)
            return s;
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int start=0;
        int end=0;
        
        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                if(gap==0){
                    dp[i][j]=true;
                }else if(gap==1){
                    dp[i][j]= s[i]==s[j];
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                        dp[i][j]=true;
                }
                if(dp[i][j]==true){
                    start=i;
                    end=j;
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
