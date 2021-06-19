//https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

class Solution {
public:
    
    bool isValid(vector<int> &nums,int mid,int t){
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            int x = (nums[i]%mid==0)?nums[i]/mid: (nums[i]/mid) +1;
            sum+=x;
            if(sum>t)
                return false;
        }
        return true;
    }
    
    
    int smallestDivisor(vector<int>& nums, int t) {
        int start=1;
        int end=INT_MIN;
        for(auto x:nums)
            end = max(end,x);
        int ans;
        while(start<=end){
            int mid = start+(end-start)/2;
            if(isValid(nums,mid,t)){
                ans = mid;
                end=mid-1;
            }else
                start=mid+1;
        }
        return ans;
    }
};
