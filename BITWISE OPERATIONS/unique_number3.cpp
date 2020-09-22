// We are given an array containg n numbers. All the numbers are present thrice except for one number 
// which is only present once. Find the unique number. Only use - bitwise operators, and no extra space.


#include<bits/stdc++.h>
using namespace std;

typedef long long ll ;
vector<ll> bits(64,0);


void fill_bits_array(ll n){

    ll index = 0;
    // cout<<n<<" ";
    while(n){
        if(n&1){
            // cout<<index<<" ";
            bits[index]++;
        }
        index++;
        n = n>>1;
    }
    // cout<<endl;
}

int main() {


    ll n;
    cin>>n;
    vector<ll> v(n);
    for(ll i =0;i<n;i++)
        cin>>v[i];

    for(ll i=0;i<n;i++){
        fill_bits_array(v[i]);
    }

    ll ans=0;
    // for(auto x:bits)
    //     cout<<x<<" ";
    for(ll i=0;i<n;i++){
        bits[i] = bits[i]%3;
        ans += bits[i]*pow(2,i);
    }
    cout<<ans;
    
}
