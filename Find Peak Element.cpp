/*
https://leetcode.com/problems/find-peak-element/
*/
class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int h)
    {
        int mid;
        while(l + 2 <= h)
        {
            mid = h - (h - l) / 2;
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
            {return mid;}
            
            if(nums[mid - 1] > nums[mid])
            {
                h = mid;
            }
            else
            {
                l = mid;
            }
        }
        return nums[l] > nums[h] ? l : h;
    }
    
    int findPeakElement(vector<int>& nums) {
        return binarySearch(nums, 0, nums.size() - 1);
    }
};