/*
https://leetcode.com/problems/max-number-of-k-sum-pairs/
*/

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        
        int l = 0, h = nums.size() - 1, ans = 0;
        
        while(l < h)
        {
            if(nums[l] + nums[h] == k)
            {
                l++;
                h--;
                ans++;
            }
            else if(nums[l] + nums[h] > k)
            {h--;}
            else 
            {l++;}
        }
        return ans;
    }
};
