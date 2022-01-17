/*
https://leetcode.com/problems/determine-if-string-halves-are-alike/
*/

class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {return true;}
        return false;
    }
    
    bool halvesAreAlike(string s) {
        
        int low = 0, high = s.length() - 1, lc = 0, rc = 0;
        
        while(low < high)
        {
            if(isVowel(s[low])) lc++;
            if(isVowel(s[high])) rc++;
            low++;
            high--;
        }
        
        return lc == rc;
        
    }
};
