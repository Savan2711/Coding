/*
https://leetcode.com/problems/di-string-match/
*/

class Solution {
public:
    vector<int> diStringMatch(string s) {
        
        vector<int> ans;
        int n = s.length(), st = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == 'D')
            {ans.push_back(n);n--;}
            else
            {ans.push_back(st);st++;}
        }
        
        if(s[s.length() - 1] == 'D')
        {ans.push_back(st);}
        else
        {ans.push_back(n);}
        
        return ans;
    }
};