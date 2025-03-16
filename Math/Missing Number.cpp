/*
https://leetcode.com/problems/missing-number/description/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            ans += i - nums[i];
        }
        return ans + n;
    }
};
