/*
https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/
*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> umap;
        int maxRow = 0;
        for(int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
            maxRow = max(maxRow, umap[nums[i]]);
        }

        vector<vector<int>> ans(maxRow);
        for(auto i : umap) {
            for(int j = 0; j < i.second; j++) {
                ans[j].push_back(i.first);
            }
        }
        return ans;
    }
};
