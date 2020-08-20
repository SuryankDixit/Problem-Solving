#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100005;

vector<int> graph[N];

void topoOrdering(int src,vector<bool> &visited, list<int> &ans){

    visited[src]=true;

    for(auto child:graph[src]) {
        if(!visited[child]) {
            topoOrdering(child, visited, ans);
        }
    }
    ans.push_front(src);
}

int main() {

    int vertex,edges;
    cin>>vertex>>edges;

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
//        graph[y].push_back(x);
    }
    vector<bool> visited(N,false);
    list<int> ans;
    for(int i=1;i<=vertex;i++){
        if(!visited[i]){
            topoOrdering(i,visited,ans);
        }
    }
    cout<<"Topological Ordering: "<<endl;
    for(auto x:ans)
        cout<<x<<"->";
}
// input.txt                output.txt  =>      Topological Ordering:
                                                //6->5->1->3->4->2->
//6 6
//3 4
//4 2
//5 1
//5 2
//6 1
//6 2
