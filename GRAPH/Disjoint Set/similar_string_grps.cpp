/*
839. Similar String Groups
Hard

292

97

Add to List

Share
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list A of strings.  Every string in A is an anagram of every other string in A.  How many groups are there?

 

Example 1:

Input: A = ["tars","rats","arts","star"]
Output: 2
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    vector<int> parent;
    vector<int> rank;
    int sets;
    
    void disjoint_set(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        
        iota(parent.begin(),parent.end(),0); //keeps increasing values by 1;
        sets=n; // initially there are n different sets;
    }
    
    int find(int k)
    {
        if(k!=parent[k])
            parent[k]=find(parent[k]);
        return parent[k];
    }
    
    void join(int i,int j)
    {
        int x=find(i);
        int y=find(j);
        if(x!=y){
            parent[x]=y;
            sets--;
        }
    }
    
    bool similar_strings(string &a,string &b)
    {
        int count=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                count++;
                if(count>2)
                    return false;
            }
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& A) {
        disjoint_set(A.size()); // make_set;
        
        for(int i=0;i<A.size();i++)
        {
            for(int j=i+1;j<A.size();j++)
            {
                if(similar_strings(A[i],A[j]))
                    join(i,j);
            }
        }
        return sets;
    }
};