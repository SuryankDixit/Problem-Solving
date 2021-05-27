#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class graph{
    int v;
    list<int> *l;
public:
    graph(int v){
        this->v=v;
        l= new list<int>[v];
    }
    void addEdge(int x,int y){
        l[x-1].push_back(y-1);
        l[y-1].push_back(x-1);
    };

     bool dfsHelper(int node,vector<bool> &visited, vector<int> &parent){

        visited[node]=true;
        for(auto nbr:l[node]){
            if(!visited[nbr]){
                parent[nbr]=node;
                bool isCyclePresent = dfsHelper(nbr,visited,parent);
                if(isCyclePresent)
                    return true;
            }
            else if(visited[nbr] && parent[node] != nbr)
                return true;
        }
        return false;
    }

    bool findCycle(){
        vector<bool> visited(v);
        vector<int> parent(v);
        for(int i=0;i<v;i++) {
            visited[i] = false;
            parent[i]=-1;
        }
        parent[0]=-1;
        for(int i=0;i<v;i++){
            if(!visited[i]){
                bool status = dfsHelper(i,visited,parent);
                if(status==true)
                    return status;
            }
        }
        return false;
    }
};

int main() {
    graph g(5);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,1);
    bool status=g.findCycle();
    if(status){
        cout<<"Cycle is Present"<<endl;
    }
    else{
        cout<<"No cycle";
    }
    return 0;
}
