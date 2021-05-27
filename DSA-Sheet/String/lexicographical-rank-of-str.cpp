#include <bits/stdc++.h>
#include <string.h>
 
using namespace std;
const int m =  1000003;
// A utility function to find factorial of n
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}
 
// A utility function to count smaller characters on right
// of arr[low]
int findSmallerInRight(string str, int low, int high)
{
    int countRight = 0, i;
 
    for (i = low + 1; i <= high; ++i)
        if (str[i] < str[low])
            ++countRight;
 
    return countRight;
}
 
// A function to find rank of a string in all permutations
// of characters
int findRank(string str)
{
    int len = str.size();
    int mul = fact(len);
    int rank = 1;
    int countRight;
 
    int i;
    for (i = 0; i < len; ++i) {
        mul /= len - i;             
 
        // count number of chars smaller than str[i]
        // from str[i+1] to str[len-1]
        countRight = findSmallerInRight(str, i, len - 1);   //s
 
        rank += countRight * mul;
    }
 
    return rank%m;
}
 
// g i n r s t
// 0 1 2 3 4 5 
// s t r i n g

// 4*5! + 4*4! + 3*3! + 1*2! + 1*1! +1 = 598
 
// Driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        vector<int> v(256,0);
        int flag=0;
        for(int i=0;i<str.size();i++){
            // cout<< str[i]<<" ";
            v[int(str[i])]++;
            if(v[int(str[i])]>1){
                flag=1;
                cout<<0<<endl;
                break;
            }
        }
        if(flag==0)
            cout << findRank(str)<<endl;
    }
    return 0;
}