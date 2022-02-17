/*
https://leetcode.com/problems/combination-sum/
*/

class Solution {
public:
    
    vector<vector<int>> ans;
    int target;
    
    void solve(vector<int> &candidates, int l, int curSum, vector<int> &cur)
    {
        if(curSum > target) return;
        if(curSum == target) 
        {
            ans.push_back(cur);
            return;
        }
        
        for(int i = l; i < candidates.size(); i++)
        {
            if(curSum + candidates[i] <= target)
            {
                // cout << i << " ";
                cur.push_back(candidates[i]);
                curSum += candidates[i];
                solve(candidates, i, curSum, cur);
                cur.pop_back();
                curSum -= candidates[i];
            }
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int t) {
        
        target = t;
        vector<int> cur;
        solve(candidates, 0, 0, cur);
        return ans;
    
    }
};
