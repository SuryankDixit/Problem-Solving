#include <bits/stdc++.h>
using namespace std;

vector<int> usedItems;

void extend_nPr_to_nCr(vector<int> &v,int n,int r,int index,int val){

    if(val>r){
        for(auto x: v)
            cout<<x<<" ";
        cout<<endl;
        // int numZero = 0;
        // for(auto x:v){
        //     if(x==0)
        //         numZero++;
        // }
        // if(numZero==n-r){
        //     // for(auto x: v)
        //     //     cout<<x<<" ";
        //     // cout<<endl;
        // }
        return;
    }

    for(int i=index;i<n;i++){
        v[i]=val;
        extend_nPr_to_nCr(v,n,r,i+1,val+1);
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
        
    // extented nCr to nPr;
    int n,r;
    cin>>n>>r;

    usedItems.resize(r+1,0);
    vector<int> v(n,0);
    extend_nPr_to_nCr(v,n,r,0,1);
}

// input
// 5 3


// output

// 1 2 3 0 0 
// 1 2 0 3 0 
// 1 2 0 0 3 
// 1 0 2 3 0 
// 1 0 2 0 3 
// 1 0 0 2 3 
// 0 1 2 3 0 
// 0 1 2 0 3 
// 0 1 0 2 3 
// 0 0 1 2 3 
