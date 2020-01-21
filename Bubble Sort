#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef unsigned long long int ll;

int main()
{
    ll n,temp;
    scanf("%llu",&n);
    ll arr[n];
    srand(time(0)); 
    for(ll i=0;i<n;i++)
        arr[i]=rand()%1100000;
        
    //  using clock for time :
    clock_t t; 
    t = clock(); 
    
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
            }
        }
        
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("%f\n", time_taken);
    
    //for(ll i=0;i<n;i++)
    //printf("%llu ",arr[i]);
}
