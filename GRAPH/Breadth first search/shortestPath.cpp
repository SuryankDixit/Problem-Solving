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


	void shortestDistance(int source,vector<bool> &visited , vector<int> &parent,vector<int> &distance){

		queue<int> q;
		q.push(source);
		vector<int> ans;

		visited.resize(v,false);
		visited[source]=true;

		parent.resize(v,-1);
		distance.resize(v,0);

		while(!q.empty()){

			int count = q.size();
			while(count>0){
				
				int node = q.front();
				ans.push_back(node);
				q.pop();

				for(auto neighbour: adjList[node]){
					
					if(!visited[neighbour]){

						visited[neighbour]=true;
						parent[neighbour]=node;
						distance[neighbour]=distance[node]+1;
						q.push(neighbour);
					}
				}
				count--;
			}
		}

		cout<<endl;
		cout<<"Breadth First Search Path: ";
		for(auto x:ans)
			cout<<x<<" ->";

		cout<<endl<<"Distance of all the nodes from node "<<source<<" : ";
		for(auto dis: distance){
			cout<< dis<<" ";
		} 
		cout<<endl;

		cout<<"Parent of each node : ";
		for(auto x: parent){
			cout<< x<<" ";
		} 
		cout<<endl;

		int destination = 5;
		cout<<"Shortest Path of node 5 to node 0 : ";
		cout<<"5 <--- ";
		while(parent[destination]!=-1){
			cout<< parent[destination]<< " <---";
			destination = parent[destination];
		}
	}

};

int main()
{
	graph g(6);
	g.addEdge(0,1,true);
	g.addEdge(0,2,true);
	g.addEdge(0,3,true);
	g.addEdge(3,1,true);
	g.addEdge(2,1,true);
	g.addEdge(4,2,true);
	g.addEdge(1,4,true);
	g.addEdge(3,5,true);
	g.addEdge(4,5,true);
	g.printEdge();

	vector<bool> visited;
	vector<int> parent;
	vector<int> distance;

	g.shortestDistance(0,visited,parent,distance);
	return 0;
}
