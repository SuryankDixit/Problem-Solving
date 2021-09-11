#include <bits/stdc++.h>
using namespace std;

// Function to find the nCr
void printNcR(int n, int r)
{
    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else
        p = 1;
    cout << p << endl;
}
int main()
{
    int n = 50, r = 25;
    printNcR(n, r);
    return 0;
}
23280703509553