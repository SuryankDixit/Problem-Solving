class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
           int sum=0;
        for(int i=0;i<stones.size();i++)
            sum+=stones[i];
        int x=stones.size();
        int y=sum;
        
        bool dp[x+1][y+1];
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
                if(i!=0 && j!=0)
                {
                    if(stones[i-1]<=j)
                        dp[i][j]=dp[i-1][j] || dp[i-1][j-stones[i-1]];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        int diff=INT_MAX;
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[x][i]==true)
            {
                diff=sum-2*i;
                break;
            }
        }
        return diff;
    }
};
