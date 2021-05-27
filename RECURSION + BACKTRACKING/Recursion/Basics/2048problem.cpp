#include<bits/stdc++.h>

using namespace std;

unordered_map<int,string> m;
list<string> ans;
vector<string> res;

void print(int n){

	if(n<=0)
		return;

	int x = n%10;
	n = n/10;

	ans.push_front(m[x]);
	print(n);
	res.push_back(m[x]);
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
    
    int n;
    n=2048;

    m[0]="zero";
    m[1]="one";
    m[2]="two";
    m[3]="three";
    m[4]="four";
    m[5]="five";
    m[6]="six";
    m[7]="seven";
    m[8]="eight";
    m[9]="nine";

    print(n);

    for(auto x:ans)
    	cout<<x<<" ";
    cout<<endl;
    for(auto x:res)
    	cout<<x<<" ";

	return 0;
}
