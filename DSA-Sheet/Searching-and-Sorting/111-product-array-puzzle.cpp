
//User function template for C++

// nums: given vector
// return the Product vector P that hold product except self at each index
typedef long long int ll;
vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
   
    //code here        
    if(n==1)
        return {1};
    vector<ll> v(n,1);
    v[0]=nums[0];
    for(ll i=1;i<n;i++){
        v[i]=v[i-1]*nums[i];
    }
    ll temp=nums[n-1];
    v[n-1]=v[n-2];
    for(int i=n-2;i>=1;i--){
        v[i] = v[i-1]*temp;
        temp*=nums[i];
    }
    v[0]=temp;
    return v;
}
