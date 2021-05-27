#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N = 100005;

vector<int> graph[N];
vector<int> reversedGraph[N];
vector<int> components[N];

void storeOrderingOfNodes(int node,vector<int> &visited,vector<int> &order){
    visited[node]=1;
    for(auto child: graph[node]){
        if(!visited[child])
            storeOrderingOfNodes(child,visited,order);
    }
    order.push_back(node);
}

void getConnectedComponents(int node,vector<int> &visited2, int &color ){
    visited2[node]=1;
//    cout<<node<<"=>";
    for(auto child: reversedGraph[node]){
//        cout<<child<<",";
        if(!visited2[child]){
            getConnectedComponents(child,visited2,color);
        }
    }
    components[color].push_back(node);
}

int main() {
    int vertex,edges;
    cin>>vertex>>edges;

    for(int i=0;i<edges;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        reversedGraph[y].push_back(x);
    }
    vector<int> visited1(N,0);
    vector<int> visited2(N,0);
    vector<int> order;

    for(int i=1;i<=vertex;i++){
        if(!visited1[i]){
            storeOrderingOfNodes(i,visited1,order);
        }
    }
//    for(int i=0;i<order.size();i++)
//        cout<<order[i]<<" ";

    int color=1;
    for(int i=vertex;i>=1;i--){
//        cout<<endl<<order[i-1]<<"-"<<endl;
        if(!visited2[order[i-1]]){
            getConnectedComponents(order[i-1],visited2,color);
            color++;
        }
    }
    cout<<color<<endl;
    for(int i=1;i<color;i++){
        cout<<"Component "<<i<<":: ";
        for(auto nodes:components[i]){
            cout<<nodes<<"->";
        }
        cout<<endl;
    }
}

//11 17
//1 2
//2 3
//3 1
//2 4
//4 5
//5 6
//6 7
//7 5
//3 8
//3 9
//8 9
//9 10
//10 11
//11 8
//9 11
//9 7
//10 6
