/*
https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int mid = (r - l)/2 + l;
            if(nums[mid] == target) {return mid;}
            if(r == l && nums[mid] > target) {return mid;}
            if(r == l && nums[mid] < target) {return mid + 1;}
            if(nums[mid] > target) {
                r = mid;
            }
            if(nums[mid] < target) {
                l = mid + 1;
            }
        }
        return 0;
    }
};
