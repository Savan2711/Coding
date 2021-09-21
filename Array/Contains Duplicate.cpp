/*
https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> umap;
        
        for(auto i : nums)
        {
            if(umap.count(i) != 0) return true;
            umap[i]++;
        }
        return false;
    }
};