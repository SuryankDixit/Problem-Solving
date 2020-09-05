#include <bits/stdc++.h>
using namespace std;

set<string> uniquePermutation;

void permute(string &s,int i){
    // cout<<i<<" ";
    if(i == s.size()){
        uniquePermutation.insert(s);
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
    
    string s="abb";
    // cout<<s[3]<<" ";
    permute(s,0);

    for(auto x:uniquePermutation)
        cout<<x<<" ,";
    return 0;
} 
