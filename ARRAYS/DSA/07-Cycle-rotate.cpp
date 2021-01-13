#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x=a[n-1];
    for(int i=n-1;i>0;i--){
        a[i]=a[i-1];
    }
    a[0]=x;
    for(auto c:a)
        cout<<c<<" ";
    cout<<endl;
}



int main() {
 
    // #ifndef ONLINE_JUDGE    
    //     freopen("input.txt","r",stdin);
    //     freopen("output.txt","w",stdout);
    // #endif

    int t;
    cin>>t;
    while(t--){
    	solve();
    }
}

