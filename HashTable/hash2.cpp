
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
	cin>>t;
	while(t--){
	    unordered_map<char,int> m;
        string s;   // aabacbebebe
        cin>>s;
        int k;
        cin>>k;
        
        int start = 0;
        int sstart=0;
        int len = INT_MIN;
        
        int x=-1;
        // cout<<x<<endl;
	    if(k>s.size()){
	        cout<<x<<endl;
	        continue;
	    }
	   // cout<<x<<endl;
        
        for(int end=0;end<s.size();end++){
            // cout<<x<<endl;
            m[s[end]]++;
            if(m.size()>k){
                while(m.size()>k){
                    m[s[start]]--;
                    if(m[s[start]]==0)
                        m.erase(s[start]);
                    start++;
                }
            }
            else if(m.size()==k){
                if((end-start+1) > len){
                    len = end-start+1;
                    sstart = start;
                }
            }
        }
        cout<<len<<endl;
	}
    return 0;
}
