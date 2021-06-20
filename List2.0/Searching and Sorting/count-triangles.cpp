int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        int cnt=0;
        int i=0,j=n-2,k=n-1;
        while(k>=2){
            while(i<j){
                if(arr[i]+arr[j]>arr[k]){
                    cnt+=j-i;
                    // cout<<k<<" "<<cnt<<endl;
                    j--;
                    i=0;
                }else if(arr[i]+arr[j]<=arr[k]){
                    i++;
                }
            }
            k--;
            j=k-1;i=0;
        }
        return cnt;
    }