/*
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        
        bool flag = false;
        int mini = INT_MAX, maxi = INT_MIN;
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i - 1] > nums[i])
            {flag = true;}
            if(flag)
            {mini = min(nums[i], mini);}
        }
        
        flag = false;
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(nums[i + 1] < nums[i])
            {flag = true;}
            if(flag)
            {maxi = max(nums[i], maxi);}
        }
        
        int l, h;
        
        for(l = 0; l < nums.size(); l++)
        {
            if(mini < nums[l]) 
            {break;}    
        }
        
        for(h = nums.size() - 1; h >= 0; h--)
        {
            if(maxi > nums[h]) 
            {break;}    
        }
        
        return h - l < 0 ? 0 : h - l + 1;
    }
};
