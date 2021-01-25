#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    stack<char> a;
	    for(auto x:s){
	       if(x=='{'){
	           a.push(x);
	       }else if(!a.empty() && (x=='}' && a.top()=='{')){
	           a.pop();
	       }else{
	           a.push(x);
	       }
	    }
	    if(a.size()%2!=0)
	        cout<<-1<<endl;
	   else{
	        double open=0;double close=0;
    	    while(!a.empty()){
    	        if(a.top()=='{'){
    	            open++;
    	        }
    	        else{
    	            close++;
    	        }
    	        a.pop();
    	    }
    	    
    	    open = ceil(open/2);
    	    close = ceil(close/2);
    	   // cout<< open<<" "<<close<<" ";
    	    int ans= open+close;
    	    cout<<ans<<endl;   
	   }
	}
	return 0;
}