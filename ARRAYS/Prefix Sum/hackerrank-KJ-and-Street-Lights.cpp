#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,p;
    cin>>n>>p;
    int arr[n][2];
    for(int i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    vector<int> v(p+1,0);
    for(int i=0;i<n;i++){
        int x = arr[i][0];
        int r = arr[i][1];
        if(x-r<0){
            v[0]+=1;
        }else{
            v[x-r]+=1;
        }
        
        if(x+r<p){
            v[x+r+1]-=1;
        }
    }
    for(int i=1;i<=p;i++){
        v[i]+=v[i-1];
    }
    
    int cnt =0 ;
    int ans =INT_MIN;
    for(int i=0;i<=p;i++){
        if(v[i]!=1){
            cnt++;
            ans = max(ans,cnt);
        }else{
            cnt = 0;
        }
    }
    cout<<ans<<endl;
    return 0;
}
