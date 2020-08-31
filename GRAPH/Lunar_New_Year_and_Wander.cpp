#include <bits/stdc++.h>
using namespace std;


const int N = 1000000;
vector<int> g[N];
vector<int> visited(N,0);
// int vertex,edges;


// void dfs(int node){
    
//     visited[node]=parity;
//     if(parity == 1)
//         col1++;
//     else if(parity ==2)
//         col2++;

//     for(auto x: g[node]){
//         if(visited[x]==0){
//             dfs(x,visited,3-parity,node);
//         }
//         else if(parent!=x && parity==visited[x]){
//             isOddCyclePresent = 1;
//             return ;
//         }
//     }
// }


int main() {
  
        int vertex,edges;
        cin>>vertex>>edges;
        
        for(int i=0;i<edges;i++){
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        
        priority_queue<int,vector<int>,greater<int>> q;
        q.push(1);
        visited[1]=1;
        
        vector<int> ans;
        
        while(!q.empty()){
            int count =q.size();
            // while(count>0){
                int node = q.top();
                q.pop();
                ans.push_back(node);
                for(auto child: g[node]){
                    if(visited[child]==0){
                        q.push(child);
                        visited[child]=1;
                    }
                }
            // }
        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
	return 0;
}
