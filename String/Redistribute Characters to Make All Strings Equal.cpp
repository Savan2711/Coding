/*
https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
*/

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int sz = words.size();
        unordered_map<char, int> umap;
        for(int i = 0; i < sz; i++)
        {
            for(int j = 0; j < words[i].length(); j++)
            {
                umap[words[i][j]]++;
            }
        }
        
        for(auto it : umap)
        {
            if(it.second % sz) return false;
        }
        return true;
    }
};
