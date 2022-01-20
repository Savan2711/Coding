/*
https://leetcode.com/problems/longest-palindrome/
*/

class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> umap;
        for(int i = 0; i < s.length(); i++)
        {
            umap[s[i]]++;
        }
        
        int ans = 0, flag = 0;;
        for(auto it : umap)
        {
            if(it.second & 1) 
            {
                flag = 1;
                ans += it.second - 1;
            }
            else
            {
                ans += it.second;
            }
        }
        if(flag) ans++;
        return ans;
        
    }
};
