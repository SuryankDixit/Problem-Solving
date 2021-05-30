class Solution {
public:
    
    vector<int> v;
    vector<vector<int>> ans;
    
    void dfs(int idx,int n,int k){
        if(v.size()>k)
            return;
        
        if(v.size()==k){
            ans.push_back(v);
            return;
        }
        
        for(int i=idx;i<=n;i++){
            v.push_back(i);
            dfs(i+1,n,k);
            v.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
    
        if(n<k){
            return ans;
        }
        dfs(1,n,k);
        return ans;
    }
};