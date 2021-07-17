/*
https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();
        vector<int> ans;
        
        if(n < 2) return ans;
        
        unordered_map<int, int> umap;
        
        for(int i = 0; i < n; i++)
        {
            if(umap.count(target - nums[i]))
            {
                ans.insert(ans.end(), {i, umap[target - nums[i]]});
                return ans;
            }
            umap[nums[i]] = i;
        }
        return ans;
    }
};