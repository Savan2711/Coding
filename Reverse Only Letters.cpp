/*
https://leetcode.com/problems/reverse-only-letters/
*/

class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        string ans = "";
        
        int r = s.length() - 1;
        
        for(int i = 0; i < s.length(); i++)
        {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                while(!((s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= 'a' && s[r] <= 'z')))
                {
                    r--;
                }
                
                ans += s[r--];
            }
            else
            {ans += s[i];}
        }
        return ans;
    }
};