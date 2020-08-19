#include<bits/stdc++.h>

using namespace std;


class graph{

	int v; 						// number of total vertex in graph
	list<int> *adjList;			// pointer to the array of lists

public:

	graph(int v){
		
		this->v = v;				// constructor to create array of lists of size v
		adjList = new list<int>[v];
	}

	void addEdge(int a,int b,bool bidirectional){

		adjList[a].push_back(b);
		if(bidirectional){
			adjList[b].push_back(a);
		}
	}

	void printEdge(){

		for(int i=0 ; i<v; i++){

			cout<<"Node "<<i<<"--> ";
			for(auto x: adjList[i]){
				cout<<x<<" ,";
			}
			cout<<endl;
		}
	}


	void bfs(int source,vector<bool> &visited){

		queue<int> q;
		q.push(source);
		vector<int> ans;
		visited.resize(v,false);
		visited[source]=true;

		while(!q.empty()){

			int count = q.size();
			while(count>0){
				
				int node = q.front();
				ans.push_back(node);
				q.pop();

				for(auto neighbours: adjList[node]){
					
					if(!visited[neighbours]){

						visited[neighbours]=true;
						q.push(neighbours);
					}
				}
				count--;
			}
		}
		cout<<endl;
		for(auto x:ans)
			cout<<x<<" ->";
	}

};

int main()
{
	graph g(5);
	g.addEdge(0,1,true);
	g.addEdge(0,2,true);
	g.addEdge(0,3,true);
	g.addEdge(3,1,true);
	g.addEdge(2,1,true);
	g.addEdge(4,2,true);
	g.addEdge(1,4,true);
	g.printEdge();

	vector<bool> visited;
	g.bfs(4,visited);
	return 0;
}
