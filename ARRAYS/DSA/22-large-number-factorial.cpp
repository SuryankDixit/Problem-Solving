#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void fact(int n){
    int i=0;
    int x=0;
    while(i<v.size()){
        x=v[i]*n+x;
        int unit =x%10;
        x=x/10;
        v[i++]=unit;
    }
    while(x>0){
        int temp = x%10;
        x=x/10;
        v.push_back(temp);
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    v.clear();
	    v.push_back(1);
	    int n;
	    cin>>n;
	    
	    for(int i=n;i>0;i--)
	        fact(i);
	        
	    for(int i=v.size()-1;i>=0;i--)
	    cout<<v[i];
	    
	    cout<<endl;
	}
	return 0;
}
