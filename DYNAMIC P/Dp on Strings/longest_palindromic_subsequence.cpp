/*
516. Longest Palindromic Subsequence
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // longest palindromic subsequence = LCS(string , Reversed string)
    
    int longestPalindromeSubseq(string s) {
        string s1=s;
        reverse(s.begin(),s.end());
        int len=LCS(s1,s);
        return len;
    }
    
    int LCS(string &s1,string &s2)
    {
        int m=s1.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][m];
    }
};
