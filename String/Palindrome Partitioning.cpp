/*
https://leetcode.com/problems/palindrome-partitioning/
*/

class Solution {
public:
    
    vector<vector<string>> ans;
    int ln;
    
    bool isPlaindrome(string &s, int l, int h)
    {
        while(l < h)
        {
            if(s[l] != s[h]) return false;
            l++;
            h--;
        }
        return true;
    }
    
    void solve(string &s, int l, vector<string> &cur, vector<vector<string>> &ans)
    {
        if(l == ln)
        {
            ans.push_back(cur);
            return;
        }
        for(int i = l; i < ln; i++)
        {
            if(isPlaindrome(s, l, i))
            {
                cur.push_back(s.substr(l, i + 1 - l));
                solve(s, i + 1, cur, ans);      
                cur.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        
        ln = s.length();
        vector<vector<string>> ans;
        vector<string> cur;
        solve(s, 0, cur, ans);
        return ans;
        
    }
};

