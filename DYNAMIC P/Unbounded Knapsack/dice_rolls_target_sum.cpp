/*
1155. Number of Dice Rolls With Target Sum

You have d dice, and each die has f faces numbered 1, 2, ..., f.
Return the number of possible ways (out of fd total ways) modulo 10^9 + 7 to roll the dice so the sum of the face up numbers equals target.

Example 1:
Input: d = 1, f = 6, target = 3
Output: 1
Explanation: 
You throw one die with 6 faces.  There is only one way to get a sum of 3.

Example 2:
Input: d = 2, f = 6, target = 7
Output: 6
Explanation: 
You throw two dice, each with 6 faces.  There are 6 ways to get a sum of 7:
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.

Example 3:
Input: d = 2, f = 5, target = 10
Output: 1
Explanation: 
You throw two dice, each with 5 faces.  Ther
*/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector <int> > dp(d+1,vector<int>(target+1,0));
        for(int i=1;i<=target && i<=f ;i++)
            dp[1][i]=1;
        
        for(int i=2;i<=d;i++)
        {
            for(int j=1;j<=target;j++)
            {
                for(int k=1;k<=f;k++)
                {
                    if(k<=j)
                        dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000000007;
                    else
                        break;
                }
            }
        }
        return dp[d][target];
    }
};
