

// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
// Examples:

// Input: arr[] = {9, 7, 5, 3},
// k = 6
// Output: True
// We can divide array into (9, 3) and
// (7, 5). Sum of both of these pairs
// is a multiple of 6.

// Input: arr[] = {92, 75, 65, 48, 45, 35},
// k = 10
// Output: True


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int k;
	    cin>>k;
	    
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++){
	        m[v[i]%k]++;
	    }
	   // for(auto x:m){
	   //     cout<<x.first<<" "<<x.second<<endl;
	   // }
	    int flag=0;
	    for(auto x:v){
	        int rem = x%k;
	        if(rem==k/2  ||  rem==0){
	            if(m[rem]&1){
	                cout<<"False"<<endl;
	                flag++;
	                break;
	            }
	        }else if(m[rem]!=m[k-rem]){
	            cout<<"False"<<endl;
	            flag++;
	            break;
	        }
	    }
	    if(flag==0)
	        cout<<"True"<<endl;
	}
	return 0;
}
