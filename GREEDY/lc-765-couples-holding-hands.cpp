#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int,int> m;
        for(int i=0;i<row.size();i++)
            m[row[i]]=i;
        int cnt=0;
        for(int i=0;i<row.size();i+=2){
            int x=row[i];
            int y=0;
            if(x%2==0)
                y=x+1;
            else
                y=x-1;              // desired value on i+1;
            if(row[i+1]!=y){
                cnt++;
                int next = row[i+1];        // actual value on i+1;     
                swap(row[m[y]], row[i+1]);  // swapping both the values
                m[next] = m[y];             // updating index of actual value in hash with tha desired value's index;
                
            }
        }
        return cnt;
    }
};