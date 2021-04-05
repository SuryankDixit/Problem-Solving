class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return {};
    
        vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int x=-1*nums[i];
            int j=i+1;
            int k=n-1;
            while(j<k){
                if(nums[j]+nums[k]== x){
                    int y=nums[j];
                    int z=nums[k];
                    ans.push_back({nums[i],nums[j],nums[k]});
                    while(j<k && nums[j]==y)
                        j++;
                    while(j<k && nums[k]==z)
                        k--;
                }else if(nums[j]+nums[k]<x){
                    j++;
                }else{
                    k--;
                }
            }
            while(i<nums.size()-1 && nums[i]==nums[i+1])
                i++;
        }
        return ans;
    }
};