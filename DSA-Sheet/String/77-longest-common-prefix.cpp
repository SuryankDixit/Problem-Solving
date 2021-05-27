#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n= strs.size();
        if(n==0)
            return "";
        string x = strs[0];
        int i =1;
        while(i<n){
            string temp = strs[i];
            int j =0;int k=0;
            string a="";
            while(j<x.size()&&k<temp.size()){
                if(x[j]==temp[k])
                    a+=x[j];
                else
                    break;
                j++;k++;
            }
            x=a;
            i++;
            if(x=="")
                return "";
        }
        return x;
    }
};