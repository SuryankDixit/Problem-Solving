
// Climb Stairs With Variable Jumps
// Try First, Check Solution later
// 1. You should first read the question and watch the question video.
// 2. Think of a solution approach, then try and submit the question on editor tab.
// 3. We strongly advise you to watch the solution video for prescribed approach.
// Question
// 1. You are given a number n, representing the number of stairs in a staircase.
// 2. You are on the 0th step and are required to climb to the top.
// 3. You are given n numbers, where ith element's value represents - till how far from the step you 
//      could jump to in a single move.  
//      You can of course jump fewer number of steps in the move.
// 4. You are required to print the number of different paths via which you can climb to the top.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
        
    vector<int> dp(n+1,0);
    
    dp[n]=1;
    
    for(int i=n-1;i>=0;i--){
        for(int j=1;j<=v[i];j++){
                
            if(i+j<=n){
                dp[i] += dp[i+j];
            }
        }
    }
    cout<<dp[0]<<endl;
}
