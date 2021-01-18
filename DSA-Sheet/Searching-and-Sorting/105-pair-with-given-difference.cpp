#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int l,n;
	    cin>>l>>n;
	    vector<int> v(l,0);
	    for(int i=0;i<l;i++)
	        cin>> v[i];
	       
	    sort(v.begin(),v.end());
	    int i=0;int j=1;
	    int flag=0;
	    while(i<l && j<l){
	        if(v[j]-v[i]==n){
	            cout<<1<<endl;
	            flag=1;
	            break;
	        }
	        if(v[j]-v[i]<n){
	            j++;
	        }else
	            i++;
	    }
	    if(flag==0)
	        cout<<-1<<endl;
	}
	return 0;
}
