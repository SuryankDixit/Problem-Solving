#include<bits/stdc++.h>

using namespace std;

int cnt=1;

template <typename T>
class graph{

	map<T,list<T>> adjList;

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

		cout<<"Component "<<cnt<<" => ";
		dfsHelper(source,visited);
		cout<<endl;

		for(auto node:adjList){
			if(visited[node.first] == false){
				cnt++;
				cout<<"Component "<<cnt<<" => ";
				dfsHelper(node.first,visited);
				cout<<endl;
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
