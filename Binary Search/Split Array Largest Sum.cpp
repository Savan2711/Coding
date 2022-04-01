/*
https://leetcode.com/problems/split-array-largest-sum/
*/

class Solution {
public:
    
    bool check(vector<int>& nums, int mid, int k)
    {
        int sum = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > mid) return false;
            
            sum += nums[i];
            
            if(sum > mid)
            {
                count++;
                sum = nums[i];
            }
        }
        count++;
        return count <= k;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int l = INT_MIN, h = 0, ans;
        for(int i = 0; i < nums.size(); i++)
        {
            l = max(l, nums[i]);
            h += nums[i];
        }
        
        int mid;
        while(l <= h)
        {
            mid = l + (h - l) / 2;
            if(check(nums, mid, m))
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return ans;
        
    }
};
