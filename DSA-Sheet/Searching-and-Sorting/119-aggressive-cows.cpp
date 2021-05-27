

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll find_cows(ll arr[], ll n, ll m);

int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll c;
        cin>>c;
        ll A[n];
        for(ll i=0;i<n;i++){
            cin>>A[i];
        }
        cout <<find_cows(A, n, c) << endl;
    }
    return 0;
}
// } Driver Code Ends


// 1 2 4 8 9

bool isValid(ll arr[],ll dis,ll c,ll n){
    ll cnt=1;
    ll prev = arr[0];
    for(ll i=1;i<n;i++){
        ll diff = arr[i]-prev;
        if(diff>=dis){
            cnt++;
            if(cnt>=c)
                return true;
            prev= arr[i];
        }
    }
    return false;
}

ll find_cows(ll arr[], ll n, ll m) {
    
    sort(arr,arr+n);
    ll start=INT_MAX;
    ll end=INT_MIN;
    start = arr[0];
    end=arr[n-1];
    
    ll ans=INT_MAX;
    while(start<=end){
        ll mid=start+(end-start)/2;
        if(isValid(arr,mid,m,n)){
            ans=mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}
