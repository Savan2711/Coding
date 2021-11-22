/*
https://leetcode.com/problems/shuffle-string/
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        string ans(s.length(), 'a');
        for(int i = 0; i < s.length(); i++)
        {
            ans[indices[i]] = s[i];
        }
        return ans; 
    }
};
