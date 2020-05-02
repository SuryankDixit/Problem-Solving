#include <bits/stdc++.h>
using namespace std;

int sumDivisors(int n)
{
    int sum=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            sum+=i;
            int divisor=n/i;
            if(i!=divisor)
            sum+=divisor;
        }
    }
    return sum;
}

int main()
{
    int n=10000;
    bool arr[n];
    memset(arr,false,sizeof(arr));
    for(int i=2;i<=sqrt(n);i++)
    {
        if(arr[i]==false)
        {
            for(int j=i*i;j<n;j+=i)
            arr[j]=true;
        }
    }
    int Sum=0;
    for(int i=2;i<n;i++)
    {
        if(arr[i]==true)
        {
            int sum1=sumDivisors(i);
            int sum2=sumDivisors(sum1);
            if(i==sum2&&sum1!=i){
                arr[i]=arr[sum1]=false;
            Sum+=i+sum1;
        }}
    }
    cout<<Sum;
}
