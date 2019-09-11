# DailyCodes
Codes will be uploaded daily on different topics.
//Rotating array elements k units left.

#include <bits/stdc++.h>

using namespace std;

int main()
{
 int n,d,j;
 cout<<"Enter the array size and rotation you want to do :";
 cin>>n;
 cin>>d;
 vector<int> v1,v2;
 for(int i=0;i<n;i++)
 {
     cin>>j;
     v1.push_back(j);
 }
 for(int i=d;i<n;i++)
     v2.push_back(v1[i]);
 for(int i=0;i<d;i++)
   v2.push_back(v1[i]);

   for(int i=0;i<v2.size();i++)
   cout<< v2[i]<<" ";
}
