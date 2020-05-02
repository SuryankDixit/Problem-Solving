// 560. Subarray Sum Equals K.

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> m;
        int sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(sum==k)
                count++;
            int temp=sum-k;
            if(m.find(temp)!=m.end())
                count+=m[temp];
            m[sum]++;
        }
        return count;
    }
};
