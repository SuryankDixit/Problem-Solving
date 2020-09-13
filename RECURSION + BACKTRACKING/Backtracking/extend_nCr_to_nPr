#include <bits/stdc++.h>
using namespace std;

vector<int> usedItems;

void extend_nCr_to_nPr(vector<int> &v,int n,int r,int index,int val){

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

    extend_nCr_to_nPr(v,n,r,index+1,val);
    for(int i = 1; i<=r ;i++){
        if(usedItems[i] ==0 ){
            usedItems[i]=1;
            v[index] = i;
            extend_nCr_to_nPr(v,n,r,index+1,val+1);
            v[index] = 0;
            usedItems[i]=0;
        }
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
    extend_nCr_to_nPr(v,n,r,0,1);
}

// input
// 5 3


// output

// 0 0 1 2 3 
// 0 0 1 3 2 
// 0 0 2 1 3 
// 0 0 2 3 1 
// 0 0 3 1 2 
// 0 0 3 2 1 
// 0 1 0 2 3 
// 0 1 0 3 2 
// 0 1 2 0 3 
// 0 1 2 3 0 
// 0 1 3 0 2 
// 0 1 3 2 0 
// 0 2 0 1 3 
// 0 2 0 3 1 
// 0 2 1 0 3 
// 0 2 1 3 0 
// 0 2 3 0 1 
// 0 2 3 1 0 
// 0 3 0 1 2 
// 0 3 0 2 1 
// 0 3 1 0 2 
// 0 3 1 2 0 
// 0 3 2 0 1 
// 0 3 2 1 0 
// 1 0 0 2 3 
// 1 0 0 3 2 
// 1 0 2 0 3 
// 1 0 2 3 0 
// 1 0 3 0 2 
// 1 0 3 2 0 
// 1 2 0 0 3 
// 1 2 0 3 0 
// 1 2 3 0 0 
// 1 3 0 0 2 
// 1 3 0 2 0 
// 1 3 2 0 0 
// 2 0 0 1 3 
// 2 0 0 3 1 
// 2 0 1 0 3 
// 2 0 1 3 0 
// 2 0 3 0 1 
// 2 0 3 1 0 
// 2 1 0 0 3 
// 2 1 0 3 0 
// 2 1 3 0 0 
// 2 3 0 0 1 
// 2 3 0 1 0 
// 2 3 1 0 0 
// 3 0 0 1 2 
// 3 0 0 2 1 
// 3 0 1 0 2 
// 3 0 1 2 0 
// 3 0 2 0 1 
// 3 0 2 1 0 
// 3 1 0 0 2 
// 3 1 0 2 0 
// 3 1 2 0 0 
// 3 2 0 0 1 
// 3 2 0 1 0 

