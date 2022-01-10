/*
https://leetcode.com/problems/reformat-the-string/
*/

class Solution {
public:
    string reformat(string s) {
        
        vector<char> digits, chars;
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {digits.push_back(s[i]);}
            else
            {chars.push_back(s[i]);}
        }
        
        int diff = digits.size() - chars.size();
        if(abs(diff) > 1) return "";
        
        s.erase();
        if(digits.size() >= chars.size())
        {
            int i = 0;
            while(i < chars.size())
            {
                s.push_back(digits[i]);
                s.push_back(chars[i]);
                i++;
            }
            if(i < digits.size()) s.push_back(digits[i]);
        }
        else
        {
            int i = 0;
            while(i < digits.size())
            {
                s.push_back(chars[i]);
                s.push_back(digits[i]);
                i++;
            }
            if(i < chars.size()) s.push_back(chars[i]);
        }
        return s;
    }
};
