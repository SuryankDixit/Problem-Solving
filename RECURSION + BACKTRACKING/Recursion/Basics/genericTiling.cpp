#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int tiling(int n,int m){
    if(n==m)
        return 2;
    if(1<=n&&n<m)
        return 1;
   

    return (tiling(n-m,m)%mod+tiling(n-1,m)%mod)%mod;
}
int main() {
    int t;
    cin>>t;
   
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<tiling(n,m)%mod<<endl;
    }
}
