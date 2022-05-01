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

/* Solution using function - 0 ms */
class Solution {
public:
    
    int process(string& s)
    {
        int p1 = -1;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != '#')
            {
                if(p1 < 0) {p1 = 0;}
                else {p1++;}
                s[p1] = s[i];
            }
            else
            {
                p1--;
            }
        }
        return p1;
    }
    
    bool backspaceCompare(string s, string t) {
        
        int p1 = process(s), p2 = process(t);
        // cout << p1 << " " << p2 << endl;
        if(p1 != p2) return false;
        
        for(int i = 0; i <= p1; i++)
        {
            if(s[i] != t[i]) return false;
        }
        
        return true;
        
    }
};
