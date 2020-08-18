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

};


int main()
{
	graph g(5);
	g.addEdge(0,1,false);
	g.addEdge(0,2,true);
	g.addEdge(0,3,true);
	g.addEdge(3,1,false);
	g.addEdge(2,1,false);
	g.addEdge(4,2,true);
	g.addEdge(1,4,true);
	g.printEdge();
	return 0;
}
