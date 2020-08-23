#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph{
    int V;
    unordered_map<T,list<pair<T,int>>> adjList;
     // hashmap of visited nodes and min distance of that node from source
public:
    explicit Graph(int n){
        V=n;
    }
    void addEdge(T x,T y, int wt,bool bidirectional){
        adjList[x].push_back(make_pair(y,wt));
        if(bidirectional) {
            adjList[y].push_back(make_pair(x,wt));
        }
    }
    void printList(){
        for(auto i:adjList){
            cout<<i<<"-->";
            for(auto j:adjList[i]){
                cout<<"("<<j.first<<","<<j.second<<")"<<",";
            }
            cout<<endl;
        }
    }

    int dijkstra(T source, T destination){
        
        unordered_map<T,int> visited;
        
        // use this initialization whether graph is directed or undirected;
        for(int i=1;i<=V;i++)
            visited[i]=INT_MAX;
        //  for(auto x:visited){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        // Taking a set that will act as a priority queue:
        set<pair<int,T>> q;                 // distance , node
        q.insert({0,source});
        visited[source]=0;
        
        // vector<int> v(V,0);

        while(!q.empty()){
            auto p = *(q.begin());       // holds the node with the least distance of all the nodes and edges
            int parentDistance = p.first;
            int parentNode = p.second;
            
            // cout<<parentNode<<"==>"<<parentDistance<<"  ";
            
            q.erase(q.begin());
            // v[parentNode]=1;

            for(auto nodePair: adjList[parentNode]){
                T childNode = nodePair.first;
                int childDistance = nodePair.second;
                int newChildDistance = childDistance+parentDistance;
                // cout<<childNode<<"=> "<<childDistance<<" "<<newChildDistance<<" "<<visited[childNode]<<",";
                if( newChildDistance < visited[childNode] ){
                    visited[childNode] = newChildDistance;
                    // cout<<childNode<<" =>"<<newChildDistance<<",";
                    auto f =q.find(make_pair(childDistance,childNode));
                    if(f!=q.end()) {
                        q.erase(f);
                        q.insert(make_pair(newChildDistance,childNode));
                    }
                    else{
                        q.insert(make_pair(newChildDistance,childNode));
                    }
                }
            }
            // cout<<endl;
        }
        // for(auto x:visited){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        return visited[destination];
    }
};


int main() {
	int t;
	cin>>t;
	while(t--){
	    int vertex,edges;
	    cin>>vertex>>edges;
	
	    Graph<int> g(vertex);
	    for(int i=0;i<edges;i++){
	        int x,y,wt;
	        cin>>x>>y>>wt;
	        g.addEdge(x,y,wt,false);
	    }
	    int a,b;
	    cin>>a>>b;
	    int shortestPath = g.dijkstra(a,b);
	    if(shortestPath!=INT_MAX)
	    	cout<<shortestPath<<endl;
	    else
	    	cout<<"NO"<<endl;
	}
    return 0;
}
