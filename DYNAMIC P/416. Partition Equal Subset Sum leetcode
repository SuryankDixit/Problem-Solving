#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
	    int n;
	    cin>>n;
	    int sum=0;
	    vector<int> nums(n);
	 
	    for(int i=0;i<n;i++){
	        cin>>nums[i];
	        sum+=nums[i];
	    }
	    if(sum%2==1) cout<<"NO"<<endl;
	    else{
	    int n = nums.size();
        int W = sum/2;
        bool dp[n+1][W+1];
        for(int i=0;i<=n;i++){
            for(int w=0;w<=W;w++){
                if(i==0){
                    dp[i][w]=false;
                }
                if(w==0){
                    dp[i][w]=true;
                }
                if(i!=0 && w!=0){
                    if(nums[i-1]<=w){
                        dp[i][w] = dp[i-1][w] || dp[i-1][w-nums[i-1]];      
                    }
                    else{
                        dp[i][w]=dp[i-1][w];
                    }
                }
            }
        }
        if(dp[n][W])
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
	    }
	  }
	return 0;
}
