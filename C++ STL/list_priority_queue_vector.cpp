#include<bits/stdc++.h>

using namespace std;

class person{
	public:
		string name;
		int age;

		person(string s,int a){
			name=s;
			age=a;
		}
};

class personCompare{
public:
	bool operator()(person a,person b){
		cout<<"comparing "<<a.age <<" with "<<b.age<<endl;
		return a.age<b.age;
	}
};
 
int main()
{

#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;i++)
		cin>>v[i];
	v.push_back(10);
	cout<<v.size()<<endl;
	for(auto x:v)
		cout<<x<<" ";

	list<string> l{"apple","mango","kiwi","banana"};
	for(auto x:l)
		cout<<x<<" ";
	cout<<endl;
	l.pop_back();
	l.pop_front();
	l.push_front("pineapple");
	l.sort(); //sort(l.begin(),l.end());
	for(auto x:l)
		cout<<x<<" ";

	
	priority_queue<person,vector<person>,personCompare> pq;

	int x;
	cin>>x;
	for(int i=0;i<x;i++){
		string s;
		int a;
		cin>>s>>a;
		person p(s,a);
		pq.push(p);
	}
	while(!pq.empty()){
		person a=pq.top();
		cout<<a.name<<" "<<a.age<<endl;
		pq.pop();
	}
    return 0;
}
