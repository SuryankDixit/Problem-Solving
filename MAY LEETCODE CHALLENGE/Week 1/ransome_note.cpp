/*
383. Ransom Note
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true
*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magzine) {
        
        unordered_map<char,int> m(26);
        
        for(int i=0;i<magzine.size();++i)
            ++m[magzine[i]];
        
        for(int i=0;i<ransomNote.size();i++)
        {
            --m[ransomNote[i]];
            if(m[ransomNote[i]]<0)
                return false;
        }
        return true;
    }
};