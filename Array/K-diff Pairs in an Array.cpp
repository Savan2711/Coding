/*
https://leetcode.com/problems/k-diff-pairs-in-an-array/
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        unordered_map<int, int> umap;
        int l = nums.size(), ans = 0;
        
        for(int i = 0; i < l; i++)
        {
            umap[nums[i]]++;    
        }
        
        if(!k)
        {
            for(auto it : umap)
            {
                if(it.second >= 2) ans++;
            }
        }
        else
        {
            for(int i = 0; i < l; i++)
            {
                if(umap[nums[i] - k] > 0 && umap[nums[i]] > 0) ans++;
                if(umap[nums[i] + k] > 0 && umap[nums[i]] > 0) ans++;
                umap[nums[i]] = 0;
            }    
        }
        
        return ans;
        
    }
        
};
