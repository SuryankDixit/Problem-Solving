#include <bits/stdc++.h>
using namespace std;


void solve(string s, int i ,int n){
    if(i>=n){
        cout<<s<<" ";
        return;
    }
    
    if(s[i]!='?'){
        solve(s,i+1,n);
    }else{
        s[i]='0';
        solve(s,i+1,n);
        s[i]='1';
        solve(s,i+1,n);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
	    cin>>s;
	    solve(s,0,s.size());
	    cout<<endl;
    }
	return 0;
}