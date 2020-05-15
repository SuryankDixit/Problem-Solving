/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        
       string ans = "";                                         // treat ans as a stack in below for loop
       
       for (char c : num) {
           while (ans.length() && ans.back() > c && k) {
               ans.pop_back();                                  // make sure digits in ans are in ascending order
               k--;                                             // remove one char
           }
           
           if (ans.length() || c != '0') { ans.push_back(c); }  // can't have leading '0'
       }
       
       while (ans.length() && k--) { ans.pop_back(); }          // make sure remove k digits in total
       
       return ans.empty() ? "0" : ans;
}
};
