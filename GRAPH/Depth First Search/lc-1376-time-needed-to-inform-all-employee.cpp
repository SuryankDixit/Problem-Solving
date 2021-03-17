#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int dfs(vector<int> graph[],int src,vector<int> &time){
        
        int ans=0;
        for(auto nbr: graph[src]){
            ans = max(ans,dfs(graph,nbr,time));
        }
        return ans+time[src];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){ 
        
        vector<int> graph[n];
        for(int i=0;i<n;i++){
            if(manager[i]==-1)
                continue;
            graph[manager[i]].push_back(i);
        }
        return dfs(graph,headID,informTime);
    }
};