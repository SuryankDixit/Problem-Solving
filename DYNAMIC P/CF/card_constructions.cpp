#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
int main() {
   
 
 
    #ifndef ONLINE_JUDGE    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
 
    vector<ll> a(1e5,0);
 
    a[0]=0;
    a[1]=2;
 
    for(int i=2;i<1e5;i++){
    	a[i] = 2*i+(i-1)+a[i-1];
    }    
    ll t;
    cin>>t;
    
    while(t--){
    	ll n;cin>>n;
    	ll cnt = 0;
    	while(true){
    		// cout<<n<<endl;
    		ll val  = lower_bound(a.begin(),a.end(),n)-a.begin();
    		
    		if(n!=a[val]){
    			val--;
    		}
    		if(val==0)break;
 
    		n= n-a[val];
    		cnt++;	
    	}
    	cout<<cnt<<endl;
 
    }
    return 0;
    
}
