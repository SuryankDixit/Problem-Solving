#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class graph{
    int v;
    list<pair<ll,ll>> *l;
public:
    graph(ll v){
        this->v=v;
        l= new list<pair<ll,ll>>[v];
    }
    void addEdge(ll x,ll y ,ll wt){
        l[x].push_back(make_pair(y,wt));
        l[y].push_back(make_pair(x,wt));
    };

    ll dfsHelper(ll node,vector<bool> &visited, vector<ll> &count,ll &ans ){

        visited[node]=true;
        count[node]=1;

        for(auto nbrs : l[node]){
            ll nbr = nbrs.first;
            ll cost = nbrs.second;
            if(!visited[nbr]){
                count[node] += dfsHelper(nbr,visited,count,ans);
                int nx = count[nbr];
                int ny = v-nx;
                ans += min(nx,ny)*2*cost;
//                cout<<ans<<" ";
            }
        }
        return count[node];
    }

    ll dfs(){
        vector<bool> visited(v);
        vector<ll> count(v);
        for(int i=0;i<v;i++) {
            visited[i] = false;
            count[i]=0;
        }

        ll ans=0;  // total distance travelled
        dfsHelper(0,visited,count,ans);
        return ans;
    }
};

int main() {

    int t;
    cin>>t;
    for(ll i=1;i<=t;i++){
        ll n;
        cin>>n;
        graph g(n);
        for(ll j=1;j<n;j++){
            int x,y,z;
            cin>>x>>y>>z;
            g.addEdge(x-1,y-1,z);
        }
        int x=g.dfs();
        cout<<"Case #"<<i<<": "<<x<<endl;
    }
    return 0;
}
