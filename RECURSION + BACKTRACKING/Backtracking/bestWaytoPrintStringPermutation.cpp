#include <bits/stdc++.h>
using namespace std;

map<char,int> m;

void permuteWithoutRepitition(string &s,int index,int n){

    // cout<<s<<endl;
    if(index >= n){
        cout<<s<<endl;
    }

    for(auto i = m.begin(); i!= m.end(); i++){

        if(i->second!=0){
            s.push_back(i->first);
            i->second = (i->second)-1;
            permuteWithoutRepitition(s,index+1,n);
            i->second = (i->second)+1;
            s.pop_back();
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
        
    string s;
    cin>>s;

    for(int i =0;i<s.size();i++){
        m[s[i]]++;
    }
    string ans;
    permuteWithoutRepitition(ans,0,s.size());
}

// input
// aabbc

// output
// aabbc
// aabcb
// aacbb
// ababc
// abacb
// abbac
// abbca
// abcab
// abcba
// acabb
// acbab
// acbba
// baabc
// baacb
// babac
// babca
// bacab
// bacba
// bbaac
// bbaca
// bbcaa
// bcaab
// bcaba
// bcbaa
// caabb
// cabab
// cabba
// cbaab
// cbaba
// cbbaa
