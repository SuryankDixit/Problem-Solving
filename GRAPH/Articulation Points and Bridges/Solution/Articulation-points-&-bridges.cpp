#include <bits/stdc++.h>
using namespace std;

const int N =100005;

vector<int> g[N];

// discovery time:  first time when a nodes is encountered;
// lowest time : minimum discovery time of a node that I can visit from subtree of x; 
// tme : time variable;

int disc[N],low[N];         
int tme=1;                                  // starting time = 1;
unordered_set<int> art_p;                   // taking set because of duplicate entries of art_p;                                                 
vector<pair<int,int>> bridge;

void dfs(int cur, int par){
    disc[cur] = low[cur] = tme++;
    int num_child=0;
    for(auto child: g[cur]){
        // if(child is not visited)         => dfs tree edge
        if(disc[child]==0){
            dfs(child,cur);
            num_child++;
            low[cur] = min(low[cur],low[child]);

            //articulation point; => root node will be handled seperately;
            if(par!=0  &&  low[child]>=disc[cur]){
                art_p.insert(cur);
            }

            // bridge;
            if(low[child] > disc[cur]){
                bridge.push_back({cur,child});
            }
        }

        //if(edge is back edge)             => back edge, cycle found
        else if(par!=child){
            low[cur] = min(low[cur],disc[child]);
        }
    }
    // seperate case for root to check whether it is articulation point or not;
    // root node must have more than 1 child in its dfs tree, only then root will be art_p;
    if(par==0 && num_child>1){
        art_p.insert(cur);
    }
}


void solve(){
    int v,e;
    cin>>v>>e;      //vertex,edges;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1,0);       // starting from node 1 whose parent is 0;
    cout<<"Articulation Points: \n";
    for(auto x:art_p){cout<<x<<" ";}
    cout<<"\nBridges: \n";
    for(auto x:bridge){cout<<x.first<<" "<<x.second<<endl;}

}


int main() {
	
	#ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;      //testcases
    cin>>t;
    while(t--){
        solve();
    }
}



//Input.txt
// 12 16
// 1 3
// 1 9
// 3 5
// 3 6
// 5 1
// 6 1
// 5 7
// 7 3
// 6 2
// 2 8
// 2 4
// 4 10
// 8 3
// 9 12
// 12 11
// 11 9



// Output.txt

// Node height
// 1      0
// 2      1
// 3      0
// 4      4
// 5      0
// 6      0
// 7      1
// 8      1
// 9      1
// 10      5
// 11      1
// 12      1




