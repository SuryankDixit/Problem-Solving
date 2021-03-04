#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        // cout<<x<<" ";
        if(parent[x]==x)
            return parent[x];
        return parent[x] = find(parent[x]);
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i]=i;
        
        int cnt=0;
        for(int i=0;i<c.size();i++){
            int x=c[i][0];
            int y=c[i][1];
            int s1=find(x);
            // cout<<endl;
            int s2=find(y);
            // cout<<endl;
            if(s1!=s2){
                parent[s1]=s2;
            }else{
                cnt++;
            }
        }
        int x=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)
                x++;
        }
        x--;
        if(x>cnt)
            return -1;
        return x;
    }
};