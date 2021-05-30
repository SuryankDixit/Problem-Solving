class Solution {
public:
    vector<int> v;
    vector<int> vis;
    vector<vector<int>> ans;
    
    void dfs(int idx, vector<int> &nums){
        if(idx>nums.size())
            return;
        
        if(idx==nums.size()){
            ans.push_back(v);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(vis[i]==0){
                v.push_back(nums[i]);
                vis[i]=1;
                dfs(idx+1,nums);
                v.pop_back();
                vis[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1){
            ans.push_back(nums);
            return ans;
        }
        
        vis.resize(nums.size(),0);
        dfs(0,nums);
        return ans;
    }
};