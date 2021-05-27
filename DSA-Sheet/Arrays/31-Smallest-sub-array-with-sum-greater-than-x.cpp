
int sb(int arr[], int n, int x)
{
    // Your code goes here   
    int start = 0;
    int sum=0;
    int Min=INT_MAX;
    for(int end=0;end<n;end++){
        sum+=arr[end];
        while(sum>x){
            sum-=arr[start++];
            Min=min(Min,end-start+2);
        }
    }
    return Min;
}
