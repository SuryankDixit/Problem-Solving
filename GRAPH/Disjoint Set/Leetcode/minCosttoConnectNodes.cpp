
//https://leetcode.com/discuss/interview-question/356981/amazon-oa-2019-min-cost-to-connect-all-nodes
#include <bits/stdc++.h>

using namespace std;

int ans =0;
vector<int> parent;

int find(int x){
    if(parent[x]==x)
        return x;
    return parent[x]= find(parent[x]);
}

void unite(int x,int y,int cost){
    int s1= find(x);
    int s2 = find(y);
    
    if(s1!=s2){
        ans+=cost;
        parent[s1]=s2;
    }
}

bool compare(vector<int> &a, vector<int> &b ){
    return a[2]<b[2];
}

int main()
{
    int n=6;
    vector<vector<int>> edges = {{1,4},{4,5},{2,3}};
    vector<vector<int>> newEdges = {{1,2,5},{1,3,10},{1,6,2},{5,6,5}};
    
    parent.resize(n+1);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    
    for(auto edge:edges){
        int x= find(edge[0]); 
        int y= find(edge[1]);
        
        if(x!=y)
            parent[x]=y;
    }
        
    sort(newEdges.begin(),newEdges.end(),compare);
    for(auto edge:newEdges){
        cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;
    }
    
    for(auto edge: newEdges){
        unite(edge[0],edge[1],edge[2]);
    }
    cout<<ans;
    return 0;
}
