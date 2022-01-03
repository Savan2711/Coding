/*
https://leetcode.com/problems/delete-characters-to-make-fancy-string/
*/

class Solution {
public:
    string makeFancyString(string s) {
        
        if(s.length() <= 2)
        {return s;}
        
        int cnt = 1;
        string ans = "";
        char prev = s[0];
        ans.push_back(prev);
        for(int i = 1; i < s.length(); i++)
        {
            if(s[i] == s[i - 1])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
                prev = s[i];
            }
            
            if(cnt <= 2)
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
