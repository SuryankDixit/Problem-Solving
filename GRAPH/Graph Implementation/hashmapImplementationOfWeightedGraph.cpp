#include<bits/stdc++.h>

using namespace std;


class graph{

	int v; 															// number of total vertex in graph
	unordered_map<string,list<pair<string,int>>> adjList;			// pointer to the array of lists

public:

	void addEdge(string a,string b,int weight,bool bidirectional){

		adjList[a].push_back(make_pair(b,weight));
		if(bidirectional){
			adjList[b].push_back(make_pair(a,weight));
		}
	}

	void printEdge(){

		for(auto p:adjList){

			string node = p.first;
			list<pair<string,int>> neighbours =p.second;
			cout<<node<<" --> ";

			for(auto neighbour: neighbours){
				cout<<"( "<<neighbour.first<<"-"<<neighbour.second<<" )"<<",";
			}
			cout<<endl;
		}
	}

};


int main()
{
	graph g;				// you can take number of vertices as input but there is no need.
	g.addEdge("A","B",1,false);
	g.addEdge("B","C",1,false);
	g.addEdge("D","C",1,false);
	g.addEdge("R","D",1,false);
	g.addEdge("P","C",1,false);
	g.addEdge("R","A",1,false);
	g.addEdge("P","R",1,false);

	g.printEdge();
	return 0;
}
