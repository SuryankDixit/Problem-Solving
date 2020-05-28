class Solution {
public:
    int dp[40][40];
    
    int mctFromLeafValues(vector<int>& arr) {
        int i=0;
        int j=arr.size()-1;
         memset(dp,-1,sizeof(dp));
        int min_cost=solve(i,j,arr);
        return min_cost;
    }
    
    int solve(int i,int j,vector<int> &arr)
    {
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int Min=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int max1,max2;
            max1=max2=INT_MIN;
            for(int x=i;x<=k;x++)
            {
                if(max1<arr[x])
                    max1=arr[x];
            }
            for(int x=k+1;x<=j;x++)
            {
                if(max2<arr[x])
                    max2=arr[x];
            }
            int temp=solve(i,k,arr)+solve(k+1,j,arr)+max1*max2;
            Min=min(temp,Min);
        }
        dp[i][j]=Min;
        return dp[i][j]; 
    }
};