/*
https://leetcode.com/problems/word-pattern/
*/

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        int plen = pattern.length(), slen = s.length();
        
        stringstream stream(s);
        
        unordered_map<char, string> umap;
        unordered_map<string, char> umap1;
        
        int i = 0;
        string word;
        while(stream >> word)
        {
            if((umap.count(pattern[i]) != 0 && umap[pattern[i]] != word) || (umap1.count(word) != 0 && umap1[word] != pattern[i])) 
            {
                return false;
            }
            umap[pattern[i]] = word;
            umap1[word] = pattern[i];
            i++;
        }
        if(i != plen) return false;
        
        i = 0;
        while(stream >> word)
        {
            if(umap[pattern[i]] != word) return false;
        }
        return true;
    }
    
};
