#include <bits/stdc++.h>
using namespace std;

void gcd(int n1,int n2)
{
    int x=max(n1,n2);
    int y=min(n1,n2);
    while(x%y!=0)
    {
        int temp=x%y;
        x=max(temp,y);
        y=min(temp,y);
    }
    cout<<"GCD of the given  umber is :"<<y;
}

int main()
{
    cout<<"Enter 2 numbers to find greatest common divisor :";
    int n1,n2;
    cin>>n1>>n2;
    gcd(n1,n2);
    return 0;
}
