//Longest common sub sequence

#include <bits/stdc++.h>
using namespace std;
const int n=1000;

int lcs(string s1,string s2,int n1,int n2,int dp[][n])
{
    if(n2==0 || n1==0)
        return 0;
    
    if(dp[n1-1][n2-1]!=-1)
        return dp[n1-1][n2-1];
    
    if(s1[n1-1]==s2[n2-1]){
        dp[n1-1][n2-1]= 1+lcs(s1,s2,n1-1,n2-1,dp);
        return dp[n1-1][n2-1];
    }
    else {
        dp[n1-1][n2-1]=max(lcs(s1,s2,n1-1,n2,dp),lcs(s1,s2,n1,n2-1,dp));
        return dp[n1-1][n2-1];
    }
}

int main()
{
    string s1="AGGTAB";
    string s2="GXTXAYB";
    int n1=s1.length();
    int n2=s2.length();
    int dp[n1][n];
    memset(dp, -1, sizeof(dp)); 
    int len=lcs(s1,s2,n1,n2,dp);
    cout<<len<<" ";
    
    return 0;
}
