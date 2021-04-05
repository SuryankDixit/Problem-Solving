#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4)
            return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int a=nums[i];
            for(int j=i+1;j<n;j++){
                int b=nums[j];
                int k=j+1;
                int l=n-1;
                while(k<l){
                    int rem=target-(a+b);
                    int c=nums[k];
                    int d=nums[l];
                    int sum=c+d;
                    if(sum==rem){
                        ans.push_back({a,b,c,d});
                        while(k<l&&nums[k]==c)
                            k++;
                        while(k<l&&nums[l]==d)
                            l--;
                    }
                    else if(sum<rem)
                        k++;
                    else
                        l--;
                }
                while(j<n-1&&nums[j]==nums[j+1])
                    j++;
            }
            while(i<n-2&&nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};