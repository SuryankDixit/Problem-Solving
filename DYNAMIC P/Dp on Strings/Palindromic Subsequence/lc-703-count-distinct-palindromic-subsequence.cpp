#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
        str = c1+m+c2
        if(c1!=c2)  dps(c1m)+dps(mc2)-dps(m);
        
        if(c1==c2)
            case 1: a----------a            middle part has no a            2*dps(m)+2
            case 2: a----a----a             middle part has common a        2*dps(m)+1
            case 3: a---a--a---a            middle part has 2 different a   2*dps(m)-dps(m')
                        m' = middle part between 2 middle a's
    */
    
    const int mod = 1e9+7;
    
    int countPalindromicSubsequences(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<int> next(n,-1);
        vector<int> prev(n,-1);
        unordered_map<char,int> m;
        
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(m.find(ch)!=m.end()){
                prev[i]=m[ch];
            }
            m[ch]=i;
        }
        
        m.clear();
        for(int i=n-1;i>=0;i--){
            char ch = s[i];
            if(m.find(ch)!=m.end()){
                next[i] = m[ch];
            }
            m[ch]=i;
        }
        
        // string of size 2 have 4 subsequence out of which always 2 are distinct
        // cout<<"HI";
        for(int gap=0;gap<n;gap++){
            for(int i=0;i<n-gap;i++){
                int j=i+gap;
                // cout<<gap<<" "<<i<<" "<<j<<endl;
                if(gap==0){
                    dp[i][i]=1;
                }else if(gap==1){
                    dp[i][j]=2;
                }else{
                    char sc = s[i];
                    char ec = s[j];
                    int n_idx = next[i];
                    int p_idx = prev[j];
                    // cout<<n_idx<<" "<<p_idx<<endl;
                    if(sc!=ec)
                        dp[i][j]= (dp[i][j-1]%mod+dp[i+1][j]-dp[i+ 1][j-1]%mod)%mod;
                    else{
                         if(n_idx > p_idx)
                             dp[i][j] = ((2*(dp[i+1][j-1]%mod))%mod+2)%mod;
                        else if(n_idx==p_idx)
                            dp[i][j] = ((2*(dp[i+1][j-1]%mod))%mod+1)%mod;
                        else
                            dp[i][j] = ((2*(dp[i+1][j-1]%mod)%mod) - dp[n_idx+1][p_idx-1])%mod;
                    }
                }
                dp[i][j] = (dp[i][j]+mod)%mod;
            }
        }
        // cout<<"Hi2";
        return dp[0][n-1]%mod;
    }
};