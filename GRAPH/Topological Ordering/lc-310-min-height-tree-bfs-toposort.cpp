class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<int> g[n];
        vector<int> degree(n,0);
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
            degree[x[1]]++;
            degree[x[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int k = q.size();
            ans.clear();
            while(k--){
                auto v = q.front();
                q.pop();
                ans.push_back(v);
                degree[v]--;
                for(auto x:g[v]){
                    degree[x]--;
                    if(degree[x]==1)
                        q.push(x);
                }
            }
        }
        return ans;
    }
};