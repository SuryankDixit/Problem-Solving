class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n,0);
        r[0]=nums[0];
        for(int i=1;i<n;i++){
            r[i]=r[i-1]+nums[i];
        }
        for(int i=n-2;i>=0;i--)
            nums[i] += nums[i+1];
        for(int i=0;i<n;i++){
            if(nums[i]==r[i])
                return i;
        }
        return -1;
    }
};