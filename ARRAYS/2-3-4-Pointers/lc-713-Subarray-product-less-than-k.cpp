class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        int n = nums.size();
        int l=0;
        int r=0;
        int cnt=0;
        int p=1;
        while(r<n){
            p=p*nums[r];
            while(p>=k&&l<=r){
                p=p/nums[l];
                l++;
            }
            cnt+=r-l+1;
            r++;
        }
        return cnt;
    }
};