/*
https://leetcode.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> result;
        set<vector<int>> ans;
        int n = nums.size();
        
        if(n < 4)
        {return result;}
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 3; i++)
        {
            for(int j = i + 1; j < n - 2; j++)
            {
                int l = j + 1, r = n - 1;
                while(l < r)
                {
                    if(nums[i] + nums[j] + nums[l] + nums[r] == target)
                    {
                        vector<int> tmp;
                        tmp.insert(tmp.end(), {nums[i], nums[j], nums[l], nums[r]});
                        // cout << "here";
                        ans.insert(tmp);
                        r--;
                    }
                    else if(nums[i] + nums[j] + nums[l] + nums[r] < target) l++;
                    else r--;
                }
            }
        }
        
        copy(ans.begin(), ans.end(), back_inserter(result));
        return result;
    }
};