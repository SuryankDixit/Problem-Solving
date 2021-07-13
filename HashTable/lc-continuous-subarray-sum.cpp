class Solution {
public:
    int n;
    bool checkSubarraySum(vector<int>& nums, int k) {
        n= nums.size();
        unordered_map<int,int> m;
        int sum=0;
        m[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int mod;
            if(k!=0)
                mod=sum%k;
            else
                mod=sum;
            if(m.find(mod)==m.end())
                m[mod]=i;
            else{
                if(i-m[mod]>=2)
                    return true;
            }
        }
        return false;
    }
};