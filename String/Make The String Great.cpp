/*
https://leetcode.com/problems/make-the-string-great/
*/

/* 3ms || Using stack*/
class Solution {
public:
    string makeGood(string s) {
        
        stack<char> stk;
        for(int i = 0; i < s.length(); i++)
        {
            if(stk.empty() || abs(stk.top() - s[i]) != 32)
            {
                stk.push(s[i]);
            }
            else
            {
                stk.pop();
            }
        }
        
        string ans = "";
        while(!stk.empty())
        {
            ans.push_back(stk.top());
            stk.pop();
        }
        return string(ans.rbegin(), ans.rend());
    }
};

/* 0ms || Using answer string as as stack */
class Solution {
public:
    string makeGood(string s) {
        
        string ans = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(ans.length() == 0 || s[i] == ans.back() || toupper(s[i]) != toupper(ans.back()))
            {
                ans.push_back(s[i]);
            }
            else
            {
                ans.pop_back();
            }
        }
        return ans;
    }
}; 
