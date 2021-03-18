// In normal sieve we can't generate array greater than 10^8 size;

#include<bits/stdc++.h>
using namespace std;

// 1 <= m <= n <= 1000000000, n-m<=100000
// Range = n-m

// n is max 10e9 , so we are pre calculating prime numbers upto sqrt(10e9)= 10e5 

const int N = 100000;
vector<int> primes;             // storing prime numbers upto 10e5;
int v[N+1] = {0};         

void sieve(){
    for(int i=2;i<=N;i++){
        if(v[i]==0){
            primes.push_back(i);
            for(int j=i;j<=N;j+=i){
                v[j]=1;
            }
        }
    }
}

void solve(){
    int m;int n;
    cin>>m>>n;  // order= 10e9;
    bool segment[n-m+1];
    for(int i=0;i<n-m+1;i++){
        segment[i]=0;
    }

    for(auto x:primes){
        // int x = primes[i];
        // cout<<x<<" ";
        if(x*x>n){
            break;
        }
        int start = (m/x)*x;        // starting point to mark true false in segment sieve;
        // cout<<x<<" "<<start<<endl;
        if(x>=m && x<=n){
            start = x*2;
            // cout<<start<<" ";
        }
        // cout<<x<<" ";
        for(int j=start;j<=n;j+=x){
            segment[j-m] = 1;
        }
    }
    // cout<<endl;
    for(int i=m;i<=n;i++){
        if(segment[i-m]==0 && i!=1){
            cout<<i<<endl;
        }
    }
    cout<<endl;
}

int main(){
    sieve();
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}