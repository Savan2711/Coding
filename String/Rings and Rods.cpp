/*
https://leetcode.com/problems/rings-and-rods/
*/

class Solution {
public:
    int countPoints(string rings) {
        
        unordered_map<char, set<char>> umap;
        
        for(int i = 1; i < rings.length(); i+=2)
        {
            umap[rings[i]].insert(rings[i - 1]);
        }
        
        int ans = 0;
        for(auto it : umap)
        {
            if(it.second.size() == 3) ans++;
        }
        return ans;
        
    }
};
