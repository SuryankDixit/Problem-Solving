#include <bits/stdc++.h>
using namespace std;

string ans;

void generatePrefixes(int n, int n0,int n1){

    if(n==0){
        cout<<ans<<endl;
        return;
    }

    ans += "1";
    generatePrefixes(n-1,n0,n1+1);
    ans.pop_back();

    if(n0+1<=n1){
        ans += "0";
        generatePrefixes(n-1,n0+1,n1);
        ans.pop_back();
    }
    return;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
 
    int n;
    cin>>n;

    // generate all the n digits binary numbers in which all the prefixes have more 1's than 0's.
    generatePrefixes(n,0,0);
    return 0;
}

