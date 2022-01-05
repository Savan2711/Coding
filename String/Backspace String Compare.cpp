/*
https://leetcode.com/problems/backspace-string-compare/
*/

/*Solution for getting string by adjusting backspace*/
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

/*Solution using two pointer*/
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        int sbcnt = 0, tbcnt = 0;
        string sback = "";
        
        int i = s.length() - 1, j = t.length() - 1;
        
        while(i >= 0 || j >= 0)
        {
            while(i >= 0)
            {
                if(s[i] == '#')
                {
                    sbcnt++;
                    i--;
                }
                else if(sbcnt)
                {
                    sbcnt--;
                    i--;
                }
                else break;
            }
            
            while(j >= 0)
            {
                if(t[j] == '#')
                {
                    tbcnt++;
                    j--;
                }
                else if(tbcnt)
                {
                    tbcnt--;
                    j--;
                }
                else break;
            }
            
            if(i >= 0 && j >= 0)
            {
                if(s[i] != t[j]) return false;
            }
            if((i >= 0) != (j >= 0)) return false;
            i--;
            j--;
        }
        return true;
    }
};
