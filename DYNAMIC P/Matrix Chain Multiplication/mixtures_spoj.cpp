#include<iostream>
#include<climits>
using namespace std;
int A[1000];
long long int dp[1000][1000];
long long sum(int s,int e){
    long long ans = 0;
    for(int i=s;i<=e;i++){
        ans+=A[i];
        ans%=100;
    }
    return ans;
}
long long  Solvemixtures(int i,int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j]=INT_MAX;
    for(int k=i;k<=j;k++){
        dp[i][j] = min(dp[i][j],Solvemixtures(i,k)+Solvemixtures(k+1,j)+sum(i,k)*sum(k+1,j));
    }
    return dp[i][j];
    
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        cout<<Solvemixtures(0,n-1)<<endl;
    }
    
}