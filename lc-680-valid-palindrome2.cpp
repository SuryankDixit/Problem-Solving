class Solution {
public:
    
    bool is_palindrome(int i,int j, string &s){
        while(i<=j){
            if(s[i]!=s[j])
                return false;
            i++;j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                int i1 = i+1;
                int j1 = j;
                int i2 = i;
                int j2 = j-1;
                return is_palindrome(i1,j1,s) || is_palindrome(i2,j2,s);
            }
            i++;j--;
        }
        return true;
    }
};