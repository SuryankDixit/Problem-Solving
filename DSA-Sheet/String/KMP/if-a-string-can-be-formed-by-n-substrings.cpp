#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int lps(string s)
	{
	    int n = s.size();
	    int j=0;
	    int i=j+1;
	    vector<int> lps(n,0);
	    
	    while(i<n){
	       if(s[i] == s[j]){
	            lps[i] = j+1;
	            j++; i++;                        //
	       }else{
	            if(j>0)
	                j=lps[j-1];
	           else{
	               lps[i]=0;
	               i++;                     //
	           }
	       }
	    }
	    return lps[n-1];
	}
	
	int isRepeat(string s)
	{
	    int x = lps(s);
	    int len = s.size()-x;
	    if(s.size()%len==0 && x>0)
	        return true;
	   return false;
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
   		cout << ob.isRepeat(str) << "\n";
   	}

    return 0;
}  // } Driver Code Ends