/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if(n%2==0)
    return false;
    
    for(int i=3;i<=sqrt(n);i+=2)
    {
     if(n%i==0)
     return false;
    }
    return true;
    
}

int main()
{
    int n=6;
    long int sum=5;
    while(n<2000000)
    {
        if(isPrime(n-1))
        {
            sum+=(n-1);
            if(n>2000000)
            break;
        }
        if(isPrime(n+1))
        {
            sum+=(n+1);
            if(n>2000000)
            break;
        }
        n+=6;
    }
    cout<<sum;
}
