/*
https://leetcode.com/problems/isomorphic-strings/
*/
class Solution {
public:
    
    bool solve(string s, string t)
    {
        unordered_map<char, char> umap;
        
        int n = s.length();
        for(int i = 0; i < n; i++)
        {
            if(umap.count(s[i]) == 0)
            {
                umap[s[i]] = t[i];
            }
            
            else 
            {if(umap[s[i]] != t[i]) return false;}
            
        }
        
        return true;
        
    }
    
    bool isIsomorphic(string s, string t) {
        
        return solve(s, t) && solve(t, s);
        
    }
};