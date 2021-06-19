//https://leetcode.com/problems/contains-duplicate-iii/submissions/

class Solution {
public:
#define int_ long long
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
        int start=0;
        for(int end=0;end<nums.size();end++){
            long n = nums[end];
            if(end>k)
                s.erase(nums[start++]);
            auto num = s.lower_bound(n-t);
            if(num!=s.end() && *num-n<=t)
                return true;
            s.insert(n);
        }
        return false;
    }
};
