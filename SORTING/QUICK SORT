
#include <bits/stdc++.h> 
using namespace std;  
  
void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  
 
int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high];  
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {  
        if (arr[j] < pivot)  
        {  
            i++;  
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  
  
void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}  

/*void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  */
 
int main()  
{  
    int n;;
    scanf("%d",&n);
    int arr[n];
    srand(time(0)); 
    for(int i=0;i<n;i++)
        arr[i]=rand()%100  ;
    
    clock_t t; 
    t = clock();
    
    quickSort(arr, 0, n - 1);  
    
     t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken : %f\n", time_taken);
    
    //cout << "Sorted array: \n";  
    //printArray(arr, n);  
    return 0;  
}
