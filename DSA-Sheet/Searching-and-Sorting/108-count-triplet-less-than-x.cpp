#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

typedef long long ll;
class Solution{
	// 1 3 4 5 7 9 11 13 15
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    ll cnt=0;
	    sort(arr,arr+n);
	    for(ll i=0;i<n-2;i++){
	        ll j=i+1;
	        ll k=n-1;
	        ll temp = arr[i];
	        ll find = sum-temp;
	        while(j<k){
	            ll x= arr[j]+arr[k];
	            if(x>=find){
	                k--;
	            }else if(x<find){
	                cnt += k-j;
	                j++;
	            }
	        }
	    }
	    return cnt;
	}
		 

};

// { Driver Code Starts.

int main() 
{
  
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	long long sum;
        cin>>n>>sum;
        long long arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
	    

       

        Solution ob;
        cout << ob.countTriplets(arr, n, sum) ;
	   
        
	    cout << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends