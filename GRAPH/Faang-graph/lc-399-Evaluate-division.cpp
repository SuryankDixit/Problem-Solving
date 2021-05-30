class Solution {
public:
    
    unordered_map<string,unordered_map<string,double>> g;
    vector<double> ans;
    unordered_set<string> vis;
    
    
    double dfs(string num,string den){
        if(g.find(num)==g.end() || g.find(den)==g.end())
            return -1;
        
        if(g[num].find(den)!=g[num].end())
            return g[num][den];
        
        for(auto x:g[num]){
            if(vis.find(x.first)==vis.end()){
                vis.insert(x.first);
                double res = x.second;
                double t = dfs(x.first,den);
                if(t!=-1)
                    return res*t;
            }
        }
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for(int i=0;i<n;i++){
            vector<string> x = equations[i];
            string num,den;
            num = x[0];
            den = x[1];
            g[num][num] = 1.0;
            g[den][den] = 1.0;
            g[num][den] = values[i];
            g[den][num] = 1/values[i];
        }
        
        for(int i=0;i<queries.size();i++){
            string num = queries[i][0];
            string den = queries[i][1];
            vis = {num};
            ans.push_back(dfs(num,den));
        }
        return ans;
    }
};