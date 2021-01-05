
// Function to find inversion count in the array

// arr[]: Input Array
// N : Size of the Array arr[
long long int merge(long long l,long long mid,long long r, long long arr[]){
    long long n1=mid-l+1;
    long long n2=r-mid;
    long long int cnt =0;
    long long a1[n1],a2[n2];
    for(int i=0;i<n1;i++){
        a1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        a2[i]=arr[mid+1+i];
    }
    
    int i=0,j=0,k=l;
    while(i<n1&&j<n2){
        if(a1[i]<=a2[j]){
            arr[k]=a1[i];
            k++;i++;
        }else if(a1[i]>a2[j]){
            arr[k]=a2[j];
            k++;j++;
            cnt+=n1-i;
        }
    }
    while(i<n1){
        arr[k]=a1[i];
        k++;i++;
    }
    while(j<n2){
        arr[k]=a2[j];
        k++;j++;
    }
    return cnt;
}

long long int mergeSort(long long l,long long r, long long arr[]){
    long long int res=0;
     if(l<r){
        int mid = l+(r-l)/2;
        res+=mergeSort(l,mid,arr);
        res+=mergeSort(mid+1,r,arr);
        res+=merge(l,mid,r,arr);
    }
    return res;
}

long long int inversionCount(long long arr[], long long n)
{
    long long l =0, r=n;
    return mergeSort(l,r-1,arr);
    // return cnt;
}