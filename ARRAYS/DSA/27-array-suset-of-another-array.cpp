#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int n1,n2;
	    cin>>n1>>n2;
	    vector<int> v1(n1,0),v2(n2,0);
	    for(int i=0;i<n1;i++){
	        cin>>v1[i];
	    }
	   for(int i=0;i<n2;i++){
	        cin>>v2[i];
	    }
	    unordered_map<int,int> m;
	    for(auto x:v1)
	        m[x]++;
	   int flag=0;
	   for(auto x:v2){
	       if(m.find(x)==m.end()){
	           flag=1;
	           cout<<"No"<<endl;
	           break;
	       }
	   }
	   if(flag==0){
	       cout<<"Yes"<<endl;
	   }
	}
	return 0;
}
