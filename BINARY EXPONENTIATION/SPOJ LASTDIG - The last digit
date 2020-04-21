#include <iostream>
using namespace std;
typedef unsigned long long int ll;

ll power(ll x,ll n)
{
    x=x%10;
    int res=1;
    while(n>0)
    {
        if(n&1)
            res=(res*x)%10;
        x=(x*x)%10;
        n>>=1;
    }
    return res; 
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        ll x,n;
        cin>>x>>n;
        ll ans=power(x,n);
        cout<<ans<<endl;
    }
    return 0;
}
