class Solution {
public:
    int r,c;
    int dp[201][201];
    
    bool isValid(int i,int j){
        if(i>=r || j>=c || i<0 || j<0)
            return false;
        return true;
    }
    
    int dfs(int i,int j,vector<vector<int>> &m){
        if(dp[i][j]!=-1)
            return dp[i][j];
        int l,r,u,d;
        l=r=u=d=0;
        if(isValid(i+1,j) && m[i+1][j]>m[i][j])
            l = dfs(i+1,j,m);
        if(isValid(i-1,j) && m[i-1][j]>m[i][j])
            r = dfs(i-1,j,m);
        if(isValid(i,j+1) && m[i][j+1]>m[i][j])
            u = dfs(i,j+1,m);
        if(isValid(i,j-1) && m[i][j-1]>m[i][j])
            d = dfs(i,j-1,m);
        dp[i][j] = max(dp[i][j], max( max(l,u), max(r,d) ))+1;
        return dp[i][j];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        r = matrix.size();
        c = matrix[0].size();
        int ans = INT_MIN;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(dp[i][j]==-1){
                    dp[i][j] = dfs(i,j,matrix);
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};