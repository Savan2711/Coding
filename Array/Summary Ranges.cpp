/*
https://leetcode.com/problems/summary-ranges/
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> ans;
        if(nums.size() == 0) return ans;
        
        string temp = to_string(nums[0]);
        
        for(int i = 1; i < nums.size() + 1; i++)
        {
            if(i == nums.size() || nums[i - 1] + 1 != nums[i])
            {
                if(to_string(nums[i - 1]) == temp)
                {
                    ans.push_back(temp);    
                }
                else
                {
                    temp += "->" + to_string(nums[i - 1]);
                    ans.push_back(temp);
                }

                if(i < nums.size())
                {
                    temp = to_string(nums[i]);
                }
            }   
        } 
        return ans;
    }
};
