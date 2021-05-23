/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Example 1:

Given nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.

It doesn't matter what you leave beyond the returned length.

*/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int index = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(index<2 || nums[i]>nums[index-2])
                nums[index++] = nums[i];                                          
        }
        return index;
        
    }
};
