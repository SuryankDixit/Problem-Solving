class Solution {
public:
    vector<int> g[2005];
    int flag=0;
    
    bool checkBipartite(int node,vector<int> &visited,int parent,int color){

        visited[node] = color;

        for(auto child:g[node]){

            if(visited[child]==false){
                bool s = checkBipartite(child,visited,node,3-color);
                if(s==false)
                    return s;
                
            }
            else if(child!=parent && visited[child]==color)
                return false;
        }
        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        for(auto x:dislikes){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        vector<int> visited(N+1,0);
        for(int i=1;i<=N;i++){
            if(visited[i]==0){
                bool status = checkBipartite(i,visited,-1,1);
                if(status ==false)
                    return false;
            }
        }
        
        return true;
    }
};