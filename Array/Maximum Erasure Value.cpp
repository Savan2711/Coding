/*
https://leetcode.com/problems/maximum-erasure-value/description/
*/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int curS = 0, ans = 0, s = 0, l = 0;
        unordered_map<int, int> umap;
        while(s <= l && l < nums.size()) {
            if(umap.find(nums[l]) == umap.end()) {
                curS += nums[l];
                umap[nums[l]] = 1;
                l++;
            }
            else {
                umap.erase(nums[s]);
                curS -= nums[s];
                s++;
            }
            ans = max(ans, curS);
        }
        return ans;
    }
};
