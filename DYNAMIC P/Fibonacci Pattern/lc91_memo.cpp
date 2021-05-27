class Solution {
public:
    
    vector<int> dp;
    
    int decode_ways(string &s, int idx){
        
        int n = s.size();
        if(idx >= n)
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int ans = 0;
        if(s[idx] != '0')
            ans += decode_ways(s,idx+1);
        if(idx <= n-2){
            if(s[idx]=='1' || (s[idx]=='2' && s[idx+1]<='6')){
                ans += decode_ways(s,idx+2);
            }
        }
        return dp[idx] = ans;
    }
    
    int numDecodings(string s) {
        
        dp.resize(s.size(),-1);
        return decode_ways(s,0);
    }
};
