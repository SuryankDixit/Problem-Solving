//length of longest palindromic subsequence

#include <bits/stdc++.h>
const int maxi = 100; 
using namespace std;

int fun(string &s,int l,int r,int dp[][maxi])
{
    if(l>r)
        return dp[l][r]= 0;
    if(l==r)
        return dp[l][r]=1;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(s[l]==s[r])
        return dp[l][r]=2+fun(s,l+1,r-1,dp);
    else
        return dp[l][r]=max(fun(s,l+1,r,dp),fun(s,l,r-1,dp));
}

int main()
{
    string s="geeksforgeeks";
    int dp[13][maxi];
    memset(dp,-1,sizeof(dp));
    int len=fun(s,0,12,dp);
    cout<<len<<endl;
    
    return 0;
}
