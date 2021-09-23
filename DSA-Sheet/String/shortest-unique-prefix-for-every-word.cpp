/*
Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is a prefix of another. Output the shortest unique prefixes in sorted order.

Input  : {"zebra", "dog", "duck", "dove"}
Output : z, dog, dov, du
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 

Input: {"geeksgeeks", "geeksquiz", "geeksforgeeks"}
Output: geeksf, geeksg, geeksq
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> uniquePrefix(vector<string> &a)
{
    int size = a.size();
    vector<string> res(size);
    sort(a.begin(), a.end());
    int j = 0;
    while (j < min(a[0].length() - 1, a[1].length() - 1))
    {
        if (a[0][j] == a[1][j])
            j++;
        else
            break;
    }
    int ind = 0;
    res[ind++] = a[0].substr(0, j + 1);

    string temp_prefix = a[1].substr(0, j + 1);
    for (int i = 1; i < size - 1; i++)
    {
        j = 0;
        while (j < min(a[i].length() - 1, a[i + 1].length() - 1))
        {
            if (a[i][j] == a[i + 1][j])
                j++;
            else
                break;
        }

        string new_prefix = a[i].substr(0, j + 1);

        if (temp_prefix.length() > new_prefix.length())
            res[ind++] = temp_prefix;
        else
            res[ind++] = new_prefix;
        temp_prefix = a[i + 1].substr(0, j + 1);
    }
    j = 0;
    string sec_last = a[size - 2];

    string last = a[size - 1];

    while (j < min(sec_last.length() - 1, last.length() - 1))
    {
        if (sec_last[j] == last[j])
            j++;
        else
            break;
    }

    res[ind] = last.substr(0, j + 1);
    return res;
}