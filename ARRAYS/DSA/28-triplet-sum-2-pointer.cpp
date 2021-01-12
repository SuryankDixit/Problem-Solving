
// function to find the triplet which sum to x
// arr[] : The input Array
// N : Size of the Array
// X : Sum which you need to search for 

bool find3Numbers(int a[], int n, int x)
{
    sort(a,a+n);
    for(int i=0;i<n-2;i++){
        int l = i+1;
        int r = n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==x){
                return true;
            }else if(a[l]+a[i]+a[r]<x){
                l++;
            }else{
                r--;
            }
        }
    }
    return false;
}
