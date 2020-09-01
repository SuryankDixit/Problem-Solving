#include <bits/stdc++.h>
using namespace std;

int power(int a,int n){                 // O(n)
    
    if(n==0)
        return 1;
    return a*power(a,n-1);
}

int fastPower(int a,int n){             //O(logn)
    
    if(n==0){
        return 1;
    }
    
    int ans = fastPower(a,n/2);
    ans *= ans;
    
    if(n & 1){
        return a*ans;
    }
    return ans;
}

int main() {
    
    int a =2;
    int n =12;
    cout<<power(a,n)<<endl;
    
    int x=2;
    int y=12;
    cout<<fastPower(x,y);
}
