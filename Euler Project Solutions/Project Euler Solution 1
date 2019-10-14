// Project Euler 
// Solution 1::
// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
using namespace std;
int main()
{
    //sum of first n natural numbers with n as number of terms with a as first term and l as last term.
    
    //sum= n/2(a+l);
    
    //Formula = sum(divisible by 3+divisible by 5)-sum(divisible by 15);
    
    int sum,sum1,sum2,sum3;
    sum=sum1=sum2=sum3=0;
    sum1= (333*(3+999))/2;   // sum of numbers divisible by 3 below 1000;
    sum2= (199*(5+995))/2;    // sum of numbers divisible by 5 below 1000;
    sum3= (66*(15+990))/2;    // sum of numbers divisible by 15 below 1000;
    
    sum= sum1+sum2-sum3;
    cout<< sum;
    return 0;
}
