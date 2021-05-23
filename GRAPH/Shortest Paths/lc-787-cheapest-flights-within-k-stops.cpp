#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef pair<int,int> pi;
    vector<pi> g[101];
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        for(auto x:flights)
            g[x[0]].push_back({x[1],x[2]});
        
        int k=0;
        int ans=INT_MAX;
        queue<pi> q;
        q.push({src,0});
        
        while(!q.empty()){
            if(k>K+1)
                break;
            int t=q.size();
            while(t--){
                auto x = q.front();
                q.pop();
                src = x.first;
                int dis = x.second;
                if(src==dst)
                    ans = min(ans,dis);
                for(auto a:g[src]){
                    int child = a.first;
                    int c_dis = a.second;
                    if(c_dis+dis>ans)
                        continue;
                    q.push({child,dis+c_dis});
                }
            }
            k++;
        }
        // cout<<k;
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};