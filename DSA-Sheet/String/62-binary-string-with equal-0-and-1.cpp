#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>> s;

    int cnt0 =0;int cnt1=0;
    int ans=0;
    for(auto x: s){
        if(x=='0'){
            cnt0++;
        }else if(x=='1'){
            cnt1++;
        }   
        if(cnt0==cnt1){
            ans++;
            cnt0=cnt1=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}