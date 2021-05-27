#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> v[6005];
        for(auto x:times){
            v[x[0]].push_back(make_pair(x[1],x[2]));
        }
        
        
        
        vector<int> dis(n+1,INT_MAX);
        dis[k]=0;
        set<pair<int,int>> q;   
        q.insert(make_pair(0,k));
        
        while(!q.empty()){
            auto x = *q.begin();
            int node1 = x.second;
            int d1 = x.first;
            
            q.erase(q.begin());
            
            for(auto nbr: v[node1]){
                int node2 = nbr.first;
                int dold = nbr.second;
                int dnew = d1+dold;
                if(dis[node2]>dnew){
                    dis[node2] = dnew;
                    auto f = q.find({dold,node2});
                    if(f!=q.end()){
                        q.erase(f);
                        q.insert(make_pair(dnew,node2));
                    }else
                        q.insert(make_pair(dnew,node2));
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++){
            int x = dis[i];
            cout<<x<<" ";
            if(x!=INT_MAX && x!=0){
                ans=max(ans,x);
            }else if(x==INT_MAX)
                return -1;
        }
        return ans;
    }
};