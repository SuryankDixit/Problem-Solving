#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &val, vector<int> &wt, int n,int w)
{
    if(n==0 || w==0)
        return 0;
    
    if(wt[n-1]<=w)
        return max(val[n-1]+knapsack(val,wt,n-1,w-wt[n-1]),knapsack(val,wt,n-1,w));
        
    else if(wt[n-1]>w)
        return knapsack(val,wt,n-1,w);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,w;
	    cin>>n>>w;
	    vector<int> val(n);
	    vector<int> wt(n);
	    for(int i=0;i<n;i++)
	        cin>>val[i];
	    for(int i=0;i<n;i++)
	        cin>>wt[i];
	    
	    int max_profit=knapsack(val,wt,n,w);
	    cout<<max_profit<<endl;
	}
	return 0;
}