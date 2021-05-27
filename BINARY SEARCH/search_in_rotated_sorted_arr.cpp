class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size()==0)
            return -1;
        if(nums.size()==1 && nums[0]!=target)
            return -1;
        int mid;
        int start=0;
        int end=nums.size()-1;
        while(start<end)
        {
            mid=start+(end-start)/2;
            if(nums[mid]<nums[end])
                end=mid;
            else
                start=mid+1;
        }
        int lowest_index=start;
        start=0;
        end=nums.size()-1;
        if(target>=nums[lowest_index] && target<=nums[end])
            start=lowest_index;
        else
            end=lowest_index;
        
         while(start<=end)
            {
                mid=start+(end-start)/2;
                if(nums[mid]==target)
                    return mid;
                else if(nums[mid]>target)
                    end=mid-1;
                else
                    start=mid+1;
            }
        return -1;
    }
};
