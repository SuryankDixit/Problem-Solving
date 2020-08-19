#include<bits/stdc++.h>

using namespace std;

template <typename T>
class graph{

	unordered_map<T,list<T>> adjList;

public:

	void addEdge(T a,T b){
		
		adjList[a].push_back(b);
	}

	void dfsHelper(T source , unordered_map<T,bool> &visited){

		visited[source] = true;
		cout<< source<<" ";

		for(auto vertex: adjList[source]){
			if(visited[vertex]==false){
				visited[vertex]=true;
				dfsHelper(vertex,visited);
			}
		}
	}

	void dfs(T source){

		unordered_map<T,bool> visited;
		for(auto node:adjList)
			visited[node.first]=false;


		dfsHelper(source,visited);
		for(auto node:adjList){
			if(visited[node.first] == false){
				dfsHelper(node.first,visited);
			}
		}
	}

	void printGraph(){

		for(auto x:adjList){
			cout<<x.first<<"-->";
			for(auto v:x.second){
				cout<<v<<",";
			}
			cout<<endl;
		}
	}
};

int main()
{
	graph<string> g;
	g.addEdge("a","b");
	g.addEdge("b","d");
	g.addEdge("c","e");
	g.addEdge("d","a");
	g.addEdge("e","e");
	g.addEdge("f","f");
	g.printGraph();
	g.dfs("a");
	return 0;
}
