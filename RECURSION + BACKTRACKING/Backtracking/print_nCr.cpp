#include <bits/stdc++.h>
using namespace std;

void print_nCr(vector<int> &v,int n,int r,int index){

    if(index>=n){
        int numZero = 0;
        for(auto x:v){
            if(x==0)
                numZero++;
        }
        if(numZero==n-r){
            for(auto x: v)
                cout<<x<<" ";
            cout<<endl;
        }
        return;
    }

    print_nCr(v,n,r,index+1);
    v[index] = 1;
    print_nCr(v,n,r,index+1);
    v[index] = 0;
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        
    // fill n places with k identical items and fill remaining place with 0
    int n,r;
    cin>>n>>r;

    vector<int> v(n,0);
    print_nCr(v,n,r,0);
}

// input
// 6 4


// output

// 0 0 1 1 1 1 
// 0 1 0 1 1 1 
// 0 1 1 0 1 1 
// 0 1 1 1 0 1 
// 0 1 1 1 1 0 
// 1 0 0 1 1 1 
// 1 0 1 0 1 1 
// 1 0 1 1 0 1 
// 1 0 1 1 1 0 
// 1 1 0 0 1 1 
// 1 1 0 1 0 1 
// 1 1 0 1 1 0 
// 1 1 1 0 0 1 
// 1 1 1 0 1 0 
// 1 1 1 1 0 0 
