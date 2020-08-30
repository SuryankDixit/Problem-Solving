// DP on graphs;

/*

Find the smallest height of a node that can be visited from a subtree of x:

*/

#include <bits/stdc++.h>
using namespace std;

const int N =10005;

vector<int> g[N];

vector<int> visited(N,0);
vector<int> depth(N);
vector<int> dp(N);


void smallest_height(int src, int par,int dep){
    
    depth[src] = dep;
    visited[src] = 1;
    dp[src] = dep;
    
    for(auto child: g[src]){
        
        if(visited[child]==0){
            
            smallest_height(child,src,dep+1);
            
            // putiing min height in the dp array from all the child and current node itself
            dp[src] = min(dp[src] , dp[child]);     
        }
        else if(child != par){      // checking for the back edge
            
            // if child is not pointing to its parent then it is a backedge;
            dp[src] = min(dp[src] , depth[child]);
            
        }
    }
}


int main() {
	
	int v,e;
	cin>>v>>e;
	for(int i=0;i<e;i++){
	    int x,y;
	    cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}
	
	// Root of tree is 1;
	// Height of root node is 0;
	// Parent of root node is 0;
	
	
	smallest_height(1,0,0);
	
	cout<<"Node"<<" "<<"height"<<endl;
	for(int i=1;i<=v;i++){
	    
	    cout<<i<<"      "<<dp[i]<<endl;
	}
	return 0;
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




