// Function to rarrange the elements in O(1) extra space
// arr: input array
// n: size of array


// encode each cell of array such that it contains 2 values.

void arrange(long long arr[], int n) {
    
    for(int i=0;i<n;i++){
        
        arr[i] = arr[i] + (arr[arr[i]] % n)*n;
    }
    for(int i=0;i<n;i++){
        
        arr[i]= arr[i]/n;
    }
    
}
