class Solution
{
    public:
    //Function to find maximum number of consecutive steps 
    //to gain an increase in altitude with each step.
    int maxStep(int A[], int N)
    {
       //Your code here
       int cnt=0;
       int ans = 0;
       for(int i=1;i<N;i++){
           if(A[i]>A[i-1]){
               cnt++;
               ans=max(ans,cnt);
           }else{
               cnt=0;
           }
       }
       return ans;
    }
};
