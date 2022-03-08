/*
https://leetcode.com/problems/delete-and-earn/
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        vector<int> sums(10001, 0);
        
        for(int i = 0; i < nums.size(); i++)
        {
            sums[nums[i]] += nums[i];
        }
        
        vector<int> dp(10001, 0);
        
        dp[1] = sums[1];
        dp[2] = max(sums[1], sums[2]);
        
        for(int i = 3; i < 10001; i++)
        {
            dp[i] = max(sums[i] + dp[i - 2], dp[i - 1]);
        }
        
        return max(dp[10000], dp[9999]);
        
    }
};
