#include<bits/stdc++.h>
using namespace std;

int find_rightmost_setBit(int x){
    int index = 0;
    while(x){
        if(x&1){
            break;
        }
        index++;
        x = x>>1;
    }
    return index;
}

int main() {

    int n;
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++)
        cin>>v[i];

    int ans =0;
    for(int i=0;i<n;i++)
        ans ^= v[i];

    // divide array into 2 parts
    int index = find_rightmost_setBit(ans);
    int mask = 1<<index;
    int set1,set2;
    set1=set2=0;
    for(auto x: v){
        if(x&mask){
            set1 ^= x;
        }else{
            set2 ^= x;
        }
    }
    if(set1<set2)
    cout<<set1<<" "<<set2;
    else    
    cout<<set2<<" "<<set1;
    return 0;
}
