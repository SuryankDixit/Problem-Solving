
int n1,n2,n3;

bool func(string a,string b,string c,int i,int j,int k,int dp[][105]){
    if(i==n1 &&j==n2 &&k==n3){
        dp[i][j]=1;
        return true;
    }
    
    if(dp[i][j]!=-1){
        if(dp[i][j]==1)
            return true;
        else
            return false;
    }
        
    if(a[i]==c[k] && b[j]==c[k]){
        bool temp= func(a,b,c,i+1,j,k+1,dp) || func(a,b,c,i,j+1,k+1,dp);
        dp[i][j]= (temp==true)?1:0;
        return temp;
    }
    else if(a[i]==c[k]){
        bool temp = func(a,b,c,i+1,j,k+1,dp);
        dp[i][j]= (temp==true)?1:0;
        return temp;
    }else if(b[j]==c[k]){
        bool temp =func(a,b,c,i,j+1,k+1,dp);
        dp[i][j]= (temp==true)?1:0;
        return temp;
    }
    dp[i][j]=0;
    return false;
}


/*You are required to complete this method */
bool isInterleave(string a, string b, string c) 
{
    //Your code here
    n1=a.size();
    n2=b.size();
    n3=c.size();
    int dp[105][105];
    for(int i=0;i<105;i++){
        for(int j=0;j<105;j++){
            dp[i][j]=-1;
        }
    }
    return func(a,b,c,0,0,0,dp);
}
