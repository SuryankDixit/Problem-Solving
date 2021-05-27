/*

    inclusion exclusion principle
`
    find number of numbers between 1 and n which are divisible by any of the prime number less than 20 
    (same like find number of numbers lesee than 1000 that are divisible by 2,3,5)
*/

#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void generateSubset(int x,vector<int> &v, int n){

    int product = 1;
    int index = 0;
    int odd_even = 0;
    while(n){
        if(n&1){
            odd_even++;
            // cout<<index<<" ";
            product *= v[index]; 
        }
        index++;
        n=n>>1;
    }
    // cout<<odd_even<<" "<<product;
    if(odd_even%2 !=0){
        ans += (x/product);
    }
    else{
        ans -= (x/product);
    }
    // cout<<" "<<ans<<endl;
}



int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n;
    cin>>n;

    
    // prime numbers less than 20;
    vector<int> v{2,3,5,7,11,13,17,19};
    
    // generate its subsets and form answer using inclusion exclusion;
    int x = v.size();
    for(int  i =1; i <= (1<<x)-1 ; i++){

        generateSubset(n,v,i);
    }
    cout<<ans<<" ";
}
