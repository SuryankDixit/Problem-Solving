#include <bits/stdc++.h>
using namespace std;

int main()
{
    bool prime[2000001];
    memset(prime,true,sizeof(prime));
    for(long int i=2;i<=sqrt(2000001);i++)
    {
        if(prime[i]==true)
        {
            for(long int j=i*i;j<2000001;j+=i)
            {
                prime[j]=false;
            }
        }
    }
    long int sum=0;
    for(int i=2;i<2000001;i++)
    {
        if(prime[i]==true)
        sum+=i;
    }
    cout<<sum;
    return 0;
}
