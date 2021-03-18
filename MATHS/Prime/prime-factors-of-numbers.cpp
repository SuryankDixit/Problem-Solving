#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
vector<int> primes;      
int v[N+1] = {0};         

void sieve(){
    for(int i=2;i*i<=N;i++){
        if(v[i]==0){
            for(int j=i*i;j<=N;j+=i){
                v[j]=1;
            }
        }
    }
    for(int i=2;i<=N;i++){
        if(v[i]==0){
            primes.push_back(i);
        }
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> factors;
    int i=0;
    int p=primes[i];
    while(p*p<=n){
        if(n%p==0){
            factors.push_back(p);
            while(n%p==0){
                n=n/p;
            }
        }
        i++;
        p=primes[i];
    }
    if(n!=1){
        factors.push_back(n);
    }
    cout<<endl;
    for(auto x:factors){
        cout<<x<<" ";
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