/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> parent(n,-1);
        
        int Max=INT_MIN;
        sort(nums.begin(),nums.end());
        
        // sorting is necessary.
        // thnk case [6,2,8];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<=dp[j]+1){
                    dp[i]=dp[j]+1;
                    parent[i]=j;
                }
            }
        }
        
        int idx=-1;
        for(int i=0;i<n;i++){
            if(Max<dp[i]){
                Max=dp[i];
                idx=i;
            }
        }
        vector<int> v;
        while(idx!=-1){
            v.push_back(nums[idx]);
            idx=parent[idx];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};
