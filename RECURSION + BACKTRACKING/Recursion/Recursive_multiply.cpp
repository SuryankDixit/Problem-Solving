#include <bits/stdc++.h>
using namespace std;


int multiply(int x,int n){
    if (n==1)
        return x;
    
    return x+multiply(x,n-1);
}


int main() {
    
   int x=7;
   int n =6;
   cout<<multiply(x,n);
}
