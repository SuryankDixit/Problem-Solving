#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>> pi;

ll min(ll a,ll b){return (a<b)?a:b;}
ll max(ll a,ll b){return (a>b)?a:b;}

int main() {
//  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 

    ll nodes,edges,time,city;
    cin>>nodes>>edges>>time>>city;
    vector<vector<ll>> cache(nodes+1,vector<ll>(nodes+1,0));
    vector<ll> graph[nodes+1];

    while(edges--){
        ll x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        cache[x][y]=1;
        cache[y][x]=1;
    }

    {
        vector<ll> vis(nodes+1,INT_MAX),par(nodes+1,-1);
        set<pair<ll,ll>> s;
        s.insert({0,1});
        while(s.size()){
            auto _pair=*s.begin();
            ll node=_pair.second;
            ll d=_pair.first;
            
            s.erase(s.begin());

            if(d<=vis[node]){
                vis[node]=d;
                for(auto i:graph[node]){
                    if(cache[node][i]==0)
                        continue;
                    ll nd=d;
                    if(vis[node]%(2*time)>=time){
                        nd+=(2*time-vis[node]%(2*time));
                    }
                    if(vis[i]>nd+city){
                        par[i]=node;
                        vis[i]=nd+city;
                        s.insert({nd+city,i});
                    }
                }
            }
        }
       

        if(vis[nodes]==INT_MAX)
        {
            cout<<-1<<endl;
            return 0;
        }
        ll x=nodes;
        while(par[x]!=-1){
            // cout<<x<<" "<<par[x]<<endl;
            // cout<<x<<endl;
            pi.push_back({x,par[x]});
            x=par[x];
        }
    }
    // return;

    ll ans=INT_MAX;
    for(auto k:pi){
        // cout<<endl;
        // cout<<k[0]<<"=="<<k[1]<<endl;
        cache[k.first][k.second]=0;
        cache[k.second][k.first]=0;

        vector<ll> vis(nodes+1,INT_MAX);
        set<pair<ll,ll>> s;
        s.insert({0,1});
        while(s.size()){
            auto it=*s.begin();
            ll node=it.second;
            ll d=it.first;
            // cout<<node<<" "<<d<<endl;
            s.erase(s.begin());

            if(d>vis[node])
                continue;
            
            vis[node]=d;
            for(auto i:graph[node]){
                if(cache[node][i]==0)
                    continue;
                ll nd=d;
                // cout<<i<<":"<<node<<" "<<nd<<" "<<d<<endl;
                if(vis[node]%(2*time)>=time){
                    nd+=(2*time-vis[node]%(2*time));
                }
                if(vis[i]>nd+city){
                    vis[i]=nd+city;
                    s.insert({nd+city,i});
                }
            }
        }
        ans=min(ans,vis[nodes]);
        // cout<<dis[n]<<endl;
        cache[k.first][k.second]=1;
        cache[k.second][k.first]=1;
    }
    if(ans==INT_MAX)
        ans=-1;
    cout<<ans<<endl;
}
/*
5 5 3 5
1 2
1 3
2 4
1 4
2 5
*/

