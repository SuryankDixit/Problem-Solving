class Solution {
public:
    
    vector<vector<int>> dp;
    
    int fun(string a, string b, int i, int j)
    {
        if(j<0)
            return 1;
        
        if(i<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(a[i]==b[j])
            return dp[i][j] = fun(a,b,i-1,j-1)+fun(a,b,i-1,j); 
        
        else
            return dp[i][j] = fun(a,b,i-1,j); 
    }
    
    int numDistinct(string a, string b) 
    {   
        int n = a.size();
        int m = b.size();
        
        dp.clear();
        dp.resize(n+1,vector<int> (m+1,-1));
        return fun(a,b,n-1,m-1);
    }
    
};