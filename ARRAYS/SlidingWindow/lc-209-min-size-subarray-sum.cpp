class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int start=0;
        int end=0;
        int sum=0;
        int ans=INT_MAX;
        while(start<n){
            sum+=nums[start];
            while(sum>=s){
                ans=min(ans,start-end+1);
                sum-=nums[end++];
            }
            start++;
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
    }
};