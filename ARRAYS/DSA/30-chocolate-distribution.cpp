#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int m;
	    cin>>m;
	    sort(v.begin(),v.end());
	    int i =0;
	    int j =i+m-1;
	    int Min=INT_MAX;
	    while(j<n){
	        int diff = v[j]-v[i];
	       // cout<<diff<<" ";
	        i++;j++;
	        Min=min(diff,Min);
	    }
	    cout<<Min<<endl;
	}
	return 0;
}
