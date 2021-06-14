
bool findPair(int arr[], int l, int n){
    //code
    int i=0,j=1;
    sort(arr,arr+l);
    while(i<l&&j<l){
        if(arr[j]-arr[i]==n){
            return true;
        }
        else if(arr[j]-arr[i]<n){
            j++;
        }else{
            i++;
        }
    }
    return false;
}