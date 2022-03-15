/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string ans = "";
        
        int st = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                st++;
            }
            else if(s[i] == ')')
            {
                if(st == 0) continue;
                st--;
            }
            ans.push_back(s[i]);
        }
        
        s = ans;
        st = 0;
        ans = "";
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ')')
            {
                st++;
            }
            else if(s[i] == '(')
            {
                if(st == 0) continue; 
                st--;
            }
            ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};
