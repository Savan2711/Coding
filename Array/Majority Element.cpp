/*
https://leetcode.com/problems/majority-element/
*/

/* Boyer-Moore Voting Algorithm -- Time complexity = O(n) -- Space complexity = O(1) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ans = 0, prev;
        for(int i = 0; i < nums.size(); i++)
        {
            if(!ans)
            {
                 prev = nums[i];
            }
            ans += nums[i] == prev ? 1 : -1;
        }
        return prev;
        
    }
};

/* Using unordered_map (frequency count) -- Time complexity = O(n) -- Space complexity = O(n) */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> umap;
        
        for(int i = 0; i < nums.size(); i++)
        {
            umap[nums[i]]++;
        }
        
        int maxi = INT_MIN, ans;
        for(auto it : umap)
        {
            if(it.second > maxi)
            {   
                maxi = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};
