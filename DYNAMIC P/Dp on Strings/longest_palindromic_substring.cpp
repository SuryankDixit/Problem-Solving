#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        
        class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size()<=1)
            return s;
        
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int len=1;
        int start=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1]=true;
                start=i;
                len=2;
            }
        }
        // cout<<start<<" "<<len;
        for(int gap=2;gap<n;gap++){
            int i=gap;
            for(int j=0;j<n-gap;j++){
                // cout<<i<<" "<<j<<endl;
                if(s[j] == s[i] ){
                    if(dp[j+1][i-1]){
                        dp[j][i] = true;
                        start=j;
                        len=i-j+1;
                    }
                }
                // cout<<start<<" "<<len;
                i++;
            }
        }
        // cout<<s.substr(start,len);
        return s.substr(start,len);
    }
};

        // for(int i=n-1;i>=0;i--)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(s[i]==s[j]){
        //             if(j==i+1 || dp[i+1][j-1]){
        //                 dp[i][j]=true;
                        
        //                 if(j-i+1>Max_len)
        //                 {
        //                     Max_len=j-i+1;
        //                     starting_point=i;
        //                 }
        //             }
        //         }
        //     }
        // }