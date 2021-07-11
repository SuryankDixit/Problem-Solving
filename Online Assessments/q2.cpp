#include<bits/stdc++.h>
using namespace std;
#define ll long long

unordered_map<ll,vector<pair<ll,ll>>> adjList;
unordered_map<ll,ll> smallestTime;

ll find_shortest_time(ll source, ll destination);

int main(){
    ll total_members;
    cin>>total_members;
    for(ll i=0;i<total_members;i++){
        ll id;
        cin>>id;
        smallestTime[id] = INT_MAX;
    }
    ll edges;
    cin>>edges;
    while(edges--){
        ll x,y,w;
        cin>>x>>y>>w;
        adjList[x].push_back({y,w});
    }
    ll source;
    cin>>source;
    ll destination;
    cin>>destination;
    int time = find_shortest_time(source,destination);
    if(time==INT_MAX){
        time=-1;
    }
    cout<<time;
}


ll find_shortest_time(ll source, ll destination){
    set<pair<ll,ll>> q;
    q.insert({0,source});
    smallestTime[source] = 0;

    while(!q.empty()){
        auto _pair = *q.begin();
        ll distance = _pair.first;
        ll parent = _pair.second;
        q.erase(q.begin());

        for(auto child_pair: adjList[parent]){
            ll childNode = child_pair.first;
            ll childDistance = child_pair.second;
            ll newDistance = childDistance + distance;
            if(newDistance < smallestTime[childNode]){
                smallestTime[childNode] = newDistance;
                if(q.find({childDistance,childNode}) != q.end()){
                    q.erase({childDistance,childNode});
                    q.insert({newDistance,childNode});
                }else{
                    q.insert({newDistance,childNode});
                }
            } 
        }
    }
    return smallestTime[destination];
}

/*
4 
2
5
7
9
4
2 9 2
7 2 3
7 9 7
9 5 1
7
9
*/

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
vector<array<int,2>> v[N];
map<int,int> mp;
int vis[N],dis[N];
int n,x,y;
int inv[N];

void help(){
  set<array<int,2>> st;
  st.insert({0,x});
  while(st.size()){
    auto it=*st.begin();
    st.erase(st.begin());
    if(it[0]>dis[it[1]]){
      continue;
    }
    dis[it[1]]=it[0];
    for(auto i:v[it[1]]){
      if(dis[i[0]]>dis[it[1]]+i[1]){
            dis[i[0]]=dis[it[1]]+i[1];
            st.insert({dis[i[0]], i[0]});
      }
    }
  }
}

signed main() {
  
  cin>>n;
  
  for(int i=1;i<=n;i++){
    cin>>x;
    inv[i]=x;
    dis[i]=1e9;
    mp[x]=i;
  }
  int m,w;
  cin>>m;
  for(int i=1;i<=m;i++){
    cin>>x>>y>>w;
    x=mp[x];
    y=mp[y];
    v[x].push_back({y,w});
  }

  cin>>x>>y;
  x=mp[x];
  y=mp[y];

  help();

  if(dis[y]==1e9)
    dis[y]=-1;
  cout<<dis[y]<<endl;
}

/*
4
2
5
7
9
4
2 9 2
7 2 3
7 9 7
9 5 1
7
9

*/