#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
  
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
   
        if (arr[mid] == x) 
            return mid; 
 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
    return -1; 
} 
  
int main(void) 
{ 
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        arr[i]=i+1;
    int key;
    scanf("%d",&key);
    
    clock_t t; 
    t = clock();
    
    int result = binarySearch(arr, 0, n - 1, key); 
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken : %f\n", time_taken);
    
    
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",result); 
    return 0; 
}
