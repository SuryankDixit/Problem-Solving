/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

*/


#include <iostream>
#include<cmath>
using namespace std;

int isPalindrome(int n)
{
    int sum=0;
    while(n>0)
    {
        sum=sum*10+n%10;
        n=n/10;
    }
    return sum;
}

bool findNumbers(int n)
{
    for(int i=999;i>=sqrt(n);i--)
    {
        if(n%i==0){
        cout<<n<<" "<<i<<" "<<n/i;
        return true;}
    }
    return false;
}

int main()
{
    for(int i=998001;i>10000;i--)
    {
        int n=isPalindrome(i);
        bool status;
        if(i==n)
        status=findNumbers(n);
        if(status==true)
        break;
    }
    return 0;
}
