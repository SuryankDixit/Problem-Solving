
int minSwap(int *arr, int n, int k) {
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]<=k)
            cnt++;
    }
    if(cnt==1)
        return  cnt-1;
    
    int start=0;
    int end=cnt-1;
    int bad=0;
    for(int i=start;i<=end;i++){
        if(arr[i]>k)
            bad++;
    }
    // cout<<cnt<<endl;
    int Min=bad;
    for(int i=end+1;i<n;i++){
        if(arr[start]>k)
            bad--;
        // cout<<bad<<" ";
        if(arr[i]>k)
            bad++;
        Min = min(Min,max(bad,0));
        // cout<<bad<<" "<<Min<<endl;
        start++;
    }
    return Min;
}
