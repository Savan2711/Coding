/*
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
*/

class Solution {
public:
    string removeDuplicates(string s) {
        
        stack<char> stk;
        
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(!stk.empty() && stk.top() == s[i])
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }
        }
        
        string ans = "";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        return ans;
    }
};
