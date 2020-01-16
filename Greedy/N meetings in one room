#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
	    int size;
	    cin>>size;
	    vector<int> v1(size);
	    vector<int> v2(size);
	    for(int j=0;j<v1.size();j++)
	    cin>>v1[j];
	    for(int j=0;j<v2.size();j++)
	    cin>>v2[j];
	   
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
	    vector<pair<int,int> > v3;
	    
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
	 //PRINTING THE SEQUENCE NUMBER OF TIMES:
	    for(auto j=v3.begin();j!=v3.end();j++)
	        {
	            for(int k=0;k<v1.size();k++)
	            {
	                if(v1[k]==j->first && v2[k]==j->second)
	                {   
	                    int l=k+1;
	                    cout<<l<<" ";
	                    break;
	            }}
	        }
	        cout<<endl;
	}
	return 0;
}
