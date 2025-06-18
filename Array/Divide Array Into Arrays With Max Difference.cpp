/*
https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/
*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 3;
        while(i <= j) {
            if(nums[i + 2] - nums[i] > k) return {};
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
            i += 3;
        }
        return ans;
    }
};
