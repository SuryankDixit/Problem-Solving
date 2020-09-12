#include <bits/stdc++.h>
using namespace std;

void print_nPr(vector<int> &v,int n,int k,int val){

    if(val>k){
        for(auto x:v)
            cout<<x<<" ";
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){
        if(v[i]!=0)
            continue;
        v[i]=val;
        print_nPr(v,n,k,val+1);
        v[i]=0;
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
        
    // fill n places with k items and fill remaining place with 0
    int n,k;
    cin>>n>>k;

    vector<int> v(n,0);
    print_nPr(v,n,k,1);
}

// input
// 4 3

// output
// 1 2 3 0 
// 1 2 0 3 
// 1 3 2 0 
// 1 0 2 3 
// 1 3 0 2 
// 1 0 3 2 
// 2 1 3 0 
// 2 1 0 3 
// 3 1 2 0 
// 0 1 2 3 
// 3 1 0 2 
// 0 1 3 2 
// 2 3 1 0 
// 2 0 1 3 
// 3 2 1 0 
// 0 2 1 3 
// 3 0 1 2 
// 0 3 1 2 
// 2 3 0 1 
// 2 0 3 1 
// 3 2 0 1 
// 0 2 3 1 
// 3 0 2 1 
// 0 3 2 1 
