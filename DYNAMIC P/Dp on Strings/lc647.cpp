/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/

class Solution {
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        if(n==1 || n==0)
            return n;
        
        int cnt=0;
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        
        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                if(gap==0){
                    dp[i][j]=true;
                }else if(gap==1){
                    if(s[i]==s[j])
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }else{
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                        dp[i][j]=true;
                    else
                        dp[i][j]=false;
                }
                if(dp[i][j]==true)
                    cnt++;
            }
        }
        return cnt;
    }
};
