#include <iostream>
using namespace std;

void merge(int arr[],int l,int m,int r);
void merge_sort(int arr[],int l,int r);

int main()
{
    int n;
    cin>>n;
    int arr[n];
    srand(time(0));
    for(int i=0;i<n;i++)
    arr[i]=rand()%100;
    
    clock_t t; 
    t = clock();
    
    merge_sort(arr,0,n-1);
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken : %f\n", time_taken);
    
    //for(int x=0;x<n;x++)
    //cout<<arr[x]<<" ";
    return 0;
}

void merge_sort(int arr[],int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++)
    L[i]=arr[l+i];
    for(int j=0;j<n2;j++)
    R[j]=arr[m+1+j];
    
    int i=0;
    int j=0;
    int k=l;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;k++;
    }
}
