class Solution {
public:
    
    vector<pair<int,int>> cnt;
    int dp[605][105][105];
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        
        cnt.resize(strs.size());
        for(int i=0;i<strs.size();i++){
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='1'){
                    (cnt[i].second)++;
                }
                else
                    (cnt[i].first)++;
            }
        }
        
        for(int i=0;i<=strs.size();i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++)
                    dp[i][j][k]= -1;
            }
        }
        
        return dfs(strs,m,n,0,dp);
    }
    
    int dfs(vector<string>& strs, int zeros, int ones, int index,int dp[][105][105]){
        
        if(index == strs.size() || (zeros<=0 && ones<=0)){
            return 0;
        }
        
        int cnt0 = cnt[index].first;
        int cnt1 = cnt[index].second;
        
        if(dp[index][zeros][ones]!= -1)
            return dp[index][zeros][ones];
        
        if(cnt0<=zeros && cnt1<=ones){
            return dp[index][zeros][ones] = max(dfs(strs,zeros-cnt0,ones-cnt1,index+1,dp)+1, dfs(strs,zeros,ones,index+1,dp));
        }
        else{
            return dp[index][zeros][ones] = dfs(strs,zeros,ones,index+1,dp);
        }
    }
};
