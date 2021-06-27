class Solution {
public:
    
    unordered_map<string,int>mp;
    bool flag=0;
    vector<int> dp;
    vector<string> ans;
    
    void dfs(string s, int idx, string v){
        
        if(idx==s.size()){
            ans.push_back(v);
            // return 1;
        }
        
        // if(dp[idx]==0)
        //     return dp[idx];
        
        string str="";
        for(int i=idx;i<s.size();i++){
            str+=s[i];
            if(mp.find(str)!=mp.end()){
                string x = v;
                if(x.size()!=0)
                    x+=" ";
                x+=str;
                dfs(s,i+1,x);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++){
           mp[wordDict[i]]++;
       }
        dp.resize(s.size(),-1);
        dfs(s,0,"");
        return ans;
    }
};
