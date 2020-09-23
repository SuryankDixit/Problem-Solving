
//Big Integers in C++


#include<bits/stdc++.h>
using namespace std;


void multiply(vector<int> &v, int num, int &index){

    int carry = 0;
    for(int  i = 0; i<index ; i++){         // iterating over array elements

        int product = num*v[i]+carry;
        v[i] = product%10;
        carry = product/10;
    }

    while(carry){

        v[index] = carry%10;
        carry = carry/10;
        index++;
    }
}


int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    vector<int> v(1000,0);

    v[0]=1;
    int x = 1;      // position upto which aarray is filled,

    for(int i = 2; i <= n; i++){

        multiply(v,i,x);
    }
    for(int i =x-1 ;i>=0;i--)
        cout<<v[i];
    return 0;   
}