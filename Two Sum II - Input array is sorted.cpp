/*
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        vector<int> ans;
        
        if(n < 2) return ans;
        
        int l = 0, r = n - 1;
        
        while(l < r)
        {
            if(numbers[l] + numbers[r] == target)
            {
                ans.insert(ans.end(), {l + 1, r + 1});
                return ans;
            }
            else if(numbers[l] + numbers[r] < target) l++;
            else r--;
        }
        return ans;
    }
};