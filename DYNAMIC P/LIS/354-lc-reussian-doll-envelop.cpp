#include<bits/stdc++.h>
using namespace std;

class Solution {
public:                                                          
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(n==0 || n==1)
            return n;
        
        sort(envelopes.begin(),envelopes.end());
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;i++){           // envelopes
            for(int j=0;j<i;j++){       // dp+envelopes
                if(envelopes[i][0]>envelopes[j][0] && envelopes[i][1]>envelopes[j][1]){
                    dp[i] = max(dp[i], dp[j]+1);
                    ans = max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};