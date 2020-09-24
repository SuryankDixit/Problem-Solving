// fast exponentiation

#include<bits/stdc++.h>
using namespace std;

int computePower(int a, int n){

    if(n==0)
        return 1;
    
    int subProblemAns = computePower(a,n/2);

    if(n&1){
        return a*subProblemAns*subProblemAns;
    }
    return subProblemAns*subProblemAns;
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    // compute a^n;
    int a,n;
    cin>>a>>n;
    cout<< computePower(a,n)<<endl;    
}