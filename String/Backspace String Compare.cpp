/*
https://leetcode.com/problems/backspace-string-compare/
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int bcnt = 0;
        string sback = "";
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] != '#' && bcnt)
            {
                bcnt--;
            }
            else if(s[i] == '#')
            {bcnt++;}
            else
            {sback.push_back(s[i]);}
            
        }
        
        bcnt = 0;
        string tback = "";
        for(int i = t.length() - 1; i >= 0; i--)
        {
            if(t[i] != '#' && bcnt)
            {
                bcnt--;
            }
            else if(t[i] == '#')
            {bcnt++;}
            else
            {tback.push_back(t[i]);}
            
        }
        return sback == tback;
    }
};
