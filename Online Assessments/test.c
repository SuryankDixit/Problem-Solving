#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int f(int n){
//     static int i
// }

int f(int *a[]){
    int i=10,j=2,k;
    a[0]=&i;a[1]=&j;*a[0]=2;
    for(k=0;k<2;k++){
        printf("%d\n",*a[k]);
    }
}

int main(){
    int a[2][3];
    f(a);
}