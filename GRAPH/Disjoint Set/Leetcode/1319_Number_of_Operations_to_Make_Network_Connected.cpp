#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    
    void unite(int x,int y){
        
        int s1= find(x);
        int s2 = find(y);
        
        if(s1!=s2)
            parent[s1]=s2;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int e = connections.size();
        int v = n;
        
        if(e < v-1)
            return -1;
        
        parent.resize(v);
        for(int i=0;i<v;i++)
            parent[i]=i;
        
        for(int i=0;i<e;i++){
            int x =connections[i][0];
            int y = connections[i][1];
            
            unite(x,y);
        }
        int ans=0;
        
        // This part of code is equivalent to finding number of connected components
        for(int i=0;i<v;i++){
            if(parent[i]==i)
                ans++;
        }
        return ans-1;
    }
};
