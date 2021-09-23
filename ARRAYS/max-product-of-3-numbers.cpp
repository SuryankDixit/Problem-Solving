class Solution
{
public:
    long long maxProduct(int arr[], int n)
    {
        // code here
        long long f, s, t;
        f = s = t = INT_MIN;
        long long f_min, s_min;
        f_min = s_min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > f)
            {
                t = s;
                s = f;
                f = arr[i];
            }
            else if (arr[i] > s)
            {
                t = s;
                s = arr[i];
            }
            else if (arr[i] > t)
            {
                t = arr[i];
            }

            if (arr[i] < f_min)
            {
                s_min = f_min;
                f_min = arr[i];
            }
            else if (arr[i] < s_min)
            {
                s_min = arr[i];
            }
        }

        long long ans = max(f * f_min * s_min, f * s * t);
        // cout<<f<<" "<<s<<" "<<t;
        return ans;
    }
};