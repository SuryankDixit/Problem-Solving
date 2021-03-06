#include <bits/stdc++.h>
using namespace std;


void printSubsets(string &in, string &out, int i){

    if(i == in.size()){
        cout<<out<<endl;
        return;
    }

    out += in[i];
    printSubsets(in,out,i+1);
    out.pop_back();

    out += toupper(in[i]);
    printSubsets(in,out,i+1);
    out.pop_back();
    return ;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    string s;
    cin>>s;
    string str="";
    printSubsets(s,str,0);

}


// input  :abc

// output
// abc
// abC
// aBc
// aBC
// Abc
// AbC
// ABc
// ABC
