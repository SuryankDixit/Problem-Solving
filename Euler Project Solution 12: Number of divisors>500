
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n=355,count=0;
    int sum=0;
    while(count<500)
    {
        count =2;
        int i;
        sum=(n*(n+1))/2;
        for(i=1;i<=sqrt(sum);i++)
        {
            if(sum%i==0)
                count+=2;
        }
        n++;
       // sum=0;    
        
    }
    cout<<n<<" "<<sum<<" "<<count;
}
