vector<int> Solution::wave(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    int i = 1;
    while (i < n)
    {
        swap(a[i], a[i - 1]);
        i += 2;
    }
    return a;
}

void sortInWave(int arr[], int n)
{
    // Traverse all even elements
    for (int i = 0; i < n; i += 2)
    {
        // If current even element is smaller than previous
        if (i > 0 && arr[i - 1] > arr[i])
            swap(&arr[i], &arr[i - 1]);

        // If current even element is smaller than next
        if (i < n - 1 && arr[i] < arr[i + 1])
            swap(&arr[i], &arr[i + 1]);
    }
}