/*
https://leetcode.com/problems/detect-capital/
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        if(word[0] >= 'A' && word[0] <= 'Z')
        {
            int i;
            for(i = 1; i < word.length(); i++)
            {
                if(word[i] < 'A' || word[i] > 'Z') break; 
            }
            if(i == word.length())
            {return true;}
        }
        
        for(int i = 1; i < word.length(); i++)
        {
            if(word[i] < 'a' || word[i] > 'z') return false; 
        }
        return true;
        
        
        
    }
};
