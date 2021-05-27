 

// What is the length of the longest suffix present till now which is also present as a prefixint the pattern. 

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//User function template for C++
class Solution{
public:		

		
	int lps(string s)
	{
	    vector<int> v(s.size(),0);
	    int n = s.size();
	    int len=0;
	    int i=1;
	    while(i<n){
	        if(s[i] == s[len]){
	            v[i]=len+1;
	            len++;i++;
	        }else{
	            if(len>0){
	                len=v[len-1];
	            }else{
	                v[i]=0;
	                i++;
	            }
	        }
	    }
	   // int ans=0;
	   // for(auto x:v){
	   //     ans=max(ans,x);
	   // }
	    return v[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends