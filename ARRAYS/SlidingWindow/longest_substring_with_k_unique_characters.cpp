#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int k;
	    cin>>k;
	    int maxLen=0;
	    int windowStart=0;
	    int windowEnd=0;
	    unordered_map<char,int> m;
	    if(k>s.size()){
	        int x=-1;
	        cout<<x<<endl;
	        continue;
	    }
	    for(windowEnd=0;windowEnd<s.size();windowEnd++){
	        m[s[windowEnd]]++;
	        while(m.size()>k){
	            m[s[windowStart]]--;
	            if(m[s[windowStart]]==0)
	                m.erase(s[windowStart]);
	            windowStart++;
	        }
	    maxLen = max(maxLen,windowEnd-windowStart+1);
	    }
	    cout<<maxLen<<endl;
	}
	return 0;
}
