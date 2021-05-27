class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> g(n,0);
        for(auto x:edges){
            g[x[1]]=1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(g[i]==0)
                ans.push_back(i);
        }
        return ans;
    }
};