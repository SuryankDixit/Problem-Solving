#include <bits/stdc++.h>
using namespace std;

void fun1(int n){
    if(n==0){
        return;
    }
        
    fun1(n-1);
    cout<<n<<" ";
    return;
}

void fun2(int n){
    if(n==0){
        return;
    }
        
    cout<<n<<" ";
    fun2(n-1);
    return;
}

int main() {
    
    int n=5;
    fun1(n);
    cout<<endl;
    fun2(n);
	return 0;
}
