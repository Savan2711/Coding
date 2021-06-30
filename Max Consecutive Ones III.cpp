/*
https://leetcode.com/problems/max-consecutive-ones-iii/
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int front = 0, back = 0, n = nums.size(), ans = 0;
        
        while(front != n)
        {
            if(!nums[front])
            {
                if(k)
                {
                    k--;
                }
                else
                {
                    while(nums[back])
                    {back++;}
                    back++;
                }
            }
            front++;
            ans = max(ans, front - back);
        }
        return ans;
    }
};