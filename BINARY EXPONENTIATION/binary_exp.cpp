// basic binary exponeniation

#include <iostream>
using namespace std;

int power(int x,int n,int y)
{
    if(n==0)
        return 1;
    if(n&1)
        return (power(x,n-1,y)*x)%y;
    else{
         int ans_=power(x,n/2,y);
         return (ans_*ans_%y)%y;
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int x,y,n;
        cin>>x>>n>>y;
        int ans=power(x,n,y);
        cout<<ans<<endl;
    }
    return 0;
}
