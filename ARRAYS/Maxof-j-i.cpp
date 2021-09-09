// https: //www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

int Solution::maximumGap(const vector<int> &A)
{
    int n = A.size();
    vector<int> l(n, INT_MAX);
    vector<int> r(n, INT_MIN);
    l[0] = A[0];
    r[n - 1] = A[n - 1];
    for (int i = 1; i < n; i++)
        l[i] = min(l[i - 1], A[i]);
    for (int i = n - 2; i >= 0; i--)
        r[i] = max(r[i + 1], A[i]);

    int i, j;
    i = j = 0;
    int ans = 0;
    while (i < n && j < n)
    {
        if (l[i] <= r[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
        {
            i++;
        }
    }
    return ans;
}
