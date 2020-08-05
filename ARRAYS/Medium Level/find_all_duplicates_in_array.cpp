class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        // using the existing array as hashtable will only work when 0<=arr[i]<=n-1
        // eg. [2,1] will not work
        
        // simply negate the every number so all the number that appears twice will  become positive.
        
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            int n = abs(nums[i]);
            nums[n-1] = -nums[n-1];
            if(nums[n-1]>0)
                v.push_back(n);
        }
        return v;   
    }
};
