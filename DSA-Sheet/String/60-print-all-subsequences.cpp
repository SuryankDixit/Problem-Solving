#include<bits/stdc++.h>
using namespace std;

set<string> s;

void solve(string & str, int i,int n,string &ans){

    if(i==n){
        s.insert(ans);
        return ;
    }

    ans+=str[i];
    solve(str,i+1,n,ans);
    ans.pop_back();
    solve(str,i+1,n,ans);
    return ;
}

int main(){
    string str;
    getline(cin,str);
    int n = str.size();
    string ans="";
    solve(str,0,n,ans);
    for(auto x:s)
        cout<<x<<" ";
    return 0;
}