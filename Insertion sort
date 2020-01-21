#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int size;
    scanf("%d",&size);      //taking array size as input
    int arr[size];
    int i;
    srand(time(0)); 
    for(i=0;i<size;i++)
        arr[i]=rand()%600000;
        
    int key;
    int j;
    
    clock_t t; 
    t = clock(); 
    
    for(i=1;i<size;i++)
    {
        key=arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(key<arr[j])
                arr[j+1]=arr[j];
            else
                break;
        }
        arr[j+1]=key;
    }
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
    printf("%f\n", time_taken);
    
    return 0;
}
