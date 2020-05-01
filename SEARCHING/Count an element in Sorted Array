#include <bits/stdc++.h>

using namespace std;

int main()
{
    int arr[]={1,2,3,4,5,5,5,5,7,8,9};
    vector<int> v(arr,arr+11);
    auto it=lower_bound(v.begin(),v.end(),5);
    int first=it-v.begin();
    it=upper_bound(v.begin(),v.end(),5);
    int last=it-v.begin();
    cout<<last-first;
    return 0;
}
