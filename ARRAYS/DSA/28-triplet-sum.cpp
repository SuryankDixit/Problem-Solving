
// function to find the triplet which sum to x
// arr[] : The input Array
// N : Size of the Array
// X : Sum which you need to search for 

bool find3Numbers(int arr[], int n, int X)
{
    
    for(int i=0;i<n-2;i++){
        unordered_map<int,int> m;
        int temp = X-arr[i];
        for(int j=i+1;j<n;j++){
            int x= temp-arr[j];
            if(m.find(x)!=m.end()){
                return true;
            }else{
                m[arr[j]]++;
            }
        }
    }
    return false;
}
