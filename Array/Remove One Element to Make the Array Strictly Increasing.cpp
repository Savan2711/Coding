/*
https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
*/

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        
        int prev = INT_MIN, flag = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] >= nums[i])
            {
                if(!flag) return false;
                flag = 0;
                if(prev >= nums[i] && i < nums.size() - 1 && nums[i - 1] >= nums[i + 1]) return false;
            }
            else
            {
                prev = nums[i - 1];
            }
        }
        return true;
    }
};
