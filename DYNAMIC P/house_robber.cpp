class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        
        if(nums.size()==2)
            return max(nums[0],nums[1]);
        
        int Max=nums[0];
        for(int i=2;i<nums.size();i++)
        {
            nums[i]=nums[i]+Max;
            Max=max(Max,nums[i-1]);
        }
        return max(nums[nums.size()-1],nums[nums.size()-2]);
    }
};
