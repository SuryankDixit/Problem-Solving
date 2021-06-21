class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> v(nums);
        sort(v.begin(),v.end());
        int idx = nums.size()-1;
        for(int i=1;i<nums.size();i+=2)
            nums[i] = v[idx--];
        for(int i=0;i<nums.size();i+=2)
            nums[i] = v[idx--];
    }
};
