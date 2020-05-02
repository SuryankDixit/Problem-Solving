//525. Contiguous Array Leetcode. Contiguous Array Leetcode

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m.insert({0,-1});
        int Max=0;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum+=-1;
            else
                sum+=1;
            auto itr=m.begin();
            if(m.find(sum)!=m.end())
            {
                itr=m.find(sum);
                Max=max(Max,(i-(itr->second)));
            }
            else
                m.insert({sum,i});
        }
        return Max;
    }
};
