class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
            return false;
        return true;
    }
    
    string reverseVowels(string s) {
        int n = s.size();
        if(n==1)
            return s;
        int i=0;int j = n-1;
        while(i<j){
            while(i<j && isVowel(s[i]))
                i++;
            while(i<j && isVowel(s[j]))
                j--;
            swap(s[i],s[j]);
            i++;j--;
        }
        return s;
    }
};