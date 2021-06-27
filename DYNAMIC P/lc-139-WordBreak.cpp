class Solution {
public:
    unordered_map<string,int>mp;
    bool flag=0;
    vector<int> dp;
    
    int dfs(string s, int idx){
        
        if(idx==s.size())
            return 1;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        string str="";
        for(int i=idx;i<s.size();i++){
            str+=s[i];
            if(mp.find(str)!=mp.end()){
                cout<<str<<" ";
                if(dfs(s,i+1))
                    return dp[idx] = 1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       for(int i=0;i<wordDict.size();i++){
           mp[wordDict[i]]++;
       }
        dp.resize(s.size(),-1);
        return dfs(s,0); 
    }
};
