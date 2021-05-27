
/*
Given an array, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum.

Input:
The first line contains an integer 'T' denoting the total number of test cases. In each test cases, the first line contains an integer 'N' denoting the size of array. The second line contains N space-separated integers A1, A2, ..., AN denoting the elements of the array.


Output:
In each seperate line print minimum absolute difference.
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> arr(n,0);
	    for(int j=0;j<n;j++)
	        cin>>arr[j];
	    
	    int sum=0;
	    for(int i=0;i<n;i++)
	        sum+=arr[i];
	        
	    bool dp[n+1][(sum/2)+1];
	    for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum/2;j++)
	        {
	            if(i==0)
	                dp[0][j]=false;
	            if(j==0)
	                dp[i][0]=true;
	                
	           if(i!=0 && j!=0)
	           {
	               if(j>=arr[i-1])
	                   dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
	               else
	                   dp[i][j]=dp[i-1][j];
	           }
	        }
	    }
	   /* for(int i=0;i<=n;i++)
	    {
	        for(int j=0;j<=sum/2;j++)
	        {
	            cout<<dp[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/
	    
	    int Min=INT_MAX;
	    for(int i=sum/2;i>=0;i--)
	    {
	        if(dp[n][i]==true){
	            Min=sum-2*i;
	            break;
	        }
	    }
	    cout<<Min<<endl;
	}
	return 0;
}