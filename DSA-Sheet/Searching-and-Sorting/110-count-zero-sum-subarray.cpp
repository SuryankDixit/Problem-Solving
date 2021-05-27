
ll findSubarray(vector<ll> arr, int n ) {
    //code here
    unordered_map<ll,ll> m;
    m[0]=1;
    ll sum=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(m.find(sum)!=m.end()){
            ans+=m[sum];
        }
        m[sum]++;
    }
    return ans;
}
