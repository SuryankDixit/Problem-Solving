#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int ans1=0;
	    for(int i=0;i<s.size();i++){
	        if(i%2==0 && s[i]!='0'){
	            ans1++;
	        }else if(i%2!=0 && s[i]!='1'){
	            ans1++;
	        }
	    }
	    int n = s.size();
	    cout<<min(ans1,(n-ans1))<<endl;
	}
	return 0;
}