//GCD AND LCM OF NUMBERS

#include <iostream>
using namespace std;
typedef long long int ll;

ll find_gcd(ll a,ll b)
{
    if(b==0)
        return a;
    else
        return find_gcd(b,a%b);
}

ll find_lcm(ll a,ll b,ll gcd)
{
    return (a*b)/gcd;
}

int main() {

	ll t;
	cin>>t;
	for(ll i=0;i<t;i++)
	{
	    ll a,b;
	    cin>>a>>b;
	    ll gcd=find_gcd(a,b);
	    
	    ll lcm= find_lcm(a,b,gcd);
	    cout<<gcd<<" "<<lcm<<endl;
	}
	return 0;
}
