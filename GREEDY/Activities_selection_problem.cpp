#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;               // number of testcases
	for(int i=0;i<T;i++)
	{
	    int size;        //array size
	    cin>>size;
	    vector<int> v1(size);
	    vector<int> v2(size);
	    for(int j=0;j<v1.size();j++)
	    cin>>v1[j];               //input of starting time of the task array.
	    for(int j=0;j<v2.size();j++)
	    cin>>v2[j];               //input of ending time of the task array.
	   
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;    // sorting on the basis of finishing time of the task using min heap
	    vector<pair<int,int> > v3;          //vector to store the resultant times
	    
	    for(int j=0;j<v1.size();j++)
	        p.push(make_pair(v2[j],v1[j]));
	    
	    auto itr=p.top();
	    int start=itr.second;
	    int finish=itr.first;
	    p.pop();
	    v3.push_back(make_pair(start,finish));
	    
	    while(!p.empty())
	    {
	        itr=p.top();
	        p.pop();
	        if(itr.second>=finish)
	        {
	            start=itr.second;
	            finish=itr.first;
	            v3.push_back(make_pair(start,finish));
	        }
	    }
	    cout<<v3.size()<<endl;
	}
	return 0;
}
