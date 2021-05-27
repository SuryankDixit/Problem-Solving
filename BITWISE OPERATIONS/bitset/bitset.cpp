#include<bits/stdc++.h>
using namespace std;

const int N = 32;

int main(){
    bitset<N> b;
    for(int i=1;i<33;i++){
        
        cout<<bitset<8>(i)<<" "<<bitset<8>(i).count()<<endl;
    }
}