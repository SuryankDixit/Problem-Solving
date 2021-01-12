class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int num=0;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(cnt==0)
                num=nums[i];
            if(num==nums[i])
                cnt++;
            else
                cnt--;
        }
        return num;
    }
};
