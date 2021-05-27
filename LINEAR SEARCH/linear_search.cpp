#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef long long int ll;

 int main()
 {
     ll n,i;
     printf("Enter array size :");
     scanf("%lld",&n);
     ll* arr = (ll*)malloc(n*sizeof(int));
     ll key;
     printf("Enter element you want to search :");
     scanf("%lld",&key);
     
    srand(time(0)); 
    for(i=0;i<n;i++)
        arr[i]=rand()%100;
     
    clock_t t; 
    t = clock();
    
    ll flag=0;
    
    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
        flag=i;
        break;
        }
    }
    
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Time taken : %f\n", time_taken);
    
    if(flag==0)
    printf("Element not found\n");
    else
    printf("Element is present at %lld position\n",flag);
    
 }
