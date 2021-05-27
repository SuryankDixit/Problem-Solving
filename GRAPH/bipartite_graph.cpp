//785. Is Graph Bipartite?
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int nodes=graph.size();
        vector<int> color(nodes,0);
        
        queue<int> q;
       
        for(int j=0;j<graph.size();j++)
        {
            if(color[j]!=0)
                continue;
            
            q.push(j);
            color[j]=1;
            
            while(!q.empty())
            {
                int v=q.front();
                q.pop();

                for(int i=0;i<graph[v].size();i++)
                {
                    int node=graph[v][i];
                    if(color[node]==0){
                        color[node] = -color[v];
                        q.push(node);

                    }
                    else if(color[v]==color[node])
                        return false;
                }
            }
        }
        for(int i=0;i<nodes;i++)
            cout<<color[i]<<" ";
        return true;
    }
};
