/*
https://leetcode.com/problems/sort-array-by-parity/
*/

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       
        int l = 0, h = nums.size() - 1;
        while(l < h)
        {
            while(l < h && !(nums[l] & 1)) {l++;}
            while(l < h && (nums[h] & 1)) {h--;}
            
            if(l < h) 
            {
                swap(nums[l], nums[h]);
                l++;
                h--;
            }
        }
        
        return nums;
        
    }
};
