class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int x = abs(nums[i]);
            nums[x-1]= -nums[x-1];
            if(nums[x-1]>0)
                ans=x;
        }
        return ans;
    }
};