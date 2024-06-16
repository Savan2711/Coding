/*
https://leetcode.com/problems/roman-to-integer/description/
*/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> umap = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int ans = umap[s[0]];
        for (int i = 1; i < s.length(); i++) {
            if(umap[s[i - 1]] < umap[s[i]]) {
                ans -= umap[s[i - 1]];
                ans += umap[s[i]] - umap[s[i - 1]];
            }
            else {
                ans += umap[s[i]];
            }
        }
        return ans;
    }
};
