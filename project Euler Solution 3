//The prime factors of 13195 are 5, 7, 13 and 29.

//What is the largest prime factor of the number 600851475143 ?


#include <iostream>
using namespace std;
long int lpf(long int n)
{
    long int count=2;
    long int max;
    while(count*count<n)
    {
        if(n%count==0)
        {
            n=n/count;
            max=count;
        }
        else
        count++;
    }
    if(n>max)
    max=n;
    return max;
}

int main()
{
    long int n,max;
    cout<<"Enter number :";
    cin>>n;
    max=lpf(n);
    cout<<max;
    return 0;
}

