#include <bits/stdc++.h>
using namespace std;

const int N=100005;
vector<int> g[N];
vector<int> time_in(N);
vector<int> time_out(N);

int timer=0;

void euler_tour(int src,vector<int> &visited){
    
    cout<<src<<" ";
    visited[src]=1;
    time_in[src] = ++timer;
    for(auto x: g[src]){
        if(visited[x]==0){
            euler_tour(x,visited);
        }
    }
    time_out[src] = timer;
}


int main() {
	
	int vertex,edges;
	cin>>vertex>>edges;
	
	for(int i=0;i<edges;i++){
	    int x,y;
	    cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}
	
	vector<int> visited(vertex,0);
	euler_tour(1,visited);
	
	for(int i=1;i<=vertex;i++)
	{
	    cout<<i<<" "<<time_in[i]<<" "<<time_out[i]<<endl;
	}
	return 0;
}
