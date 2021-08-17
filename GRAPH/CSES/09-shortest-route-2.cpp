#include<bits/stdc++.h>
using namespace std;

const int N = 501;
typedef long long ll;
ll n,m,q;

int main(){
    ll v[N][N];
    memset(v,0x3f,sizeof(v));

    cin>>n>>m>>q;

    while(m--){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        v[a][b] = min(v[a][b],c);
        v[b][a] = min(v[a][b],c);
    }

    for(int i=0;i<n;i++){
        v[i][i]=0;
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
                // cout<<v[i][j]<<" ";
            }
        }
    }

    while(q--){
        int a,b;
        cin>>a>>b , a--, b--;
        cout<<(v[a][b]>=1e18?-1:v[a][b])<<endl;
    }
    return 0;
}