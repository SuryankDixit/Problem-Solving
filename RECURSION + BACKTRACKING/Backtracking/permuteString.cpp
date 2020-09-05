#include <bits/stdc++.h>
using namespace std;

void permute(string &s,int i){
    // cout<<i<<" ";
    if(i == s.size()){
        cout<<s<<" ,";
        return;
    }
    for(int j=i;j<s.size();j++){

        swap(s[i],s[j]);
        permute(s,i+1);
        swap(s[i],s[j]);    // restoring the original array
    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    string s="abc";
    // cout<<s[3]<<" ";
    permute(s,0);
    return 0;
} 
