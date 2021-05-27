
//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    priority_queue<int> p;
    
    for(int i=0;i<=r;i++){
        if(p.size()<k){
            p.push(arr[i]);
        }else{
            if(p.top()>arr[i]){
                p.pop();
                p.push(arr[i]);
            }
        }
    }
    return p.top();
}