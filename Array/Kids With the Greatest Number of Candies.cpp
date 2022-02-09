/*
https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
*/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        
        vector<bool> ans;
        int maxi = INT_MIN;
        for(int i = 0; i < candies.size(); i++)
        {
            if(maxi < candies[i])
            {maxi = candies[i];}
        }
        
        for(int i = 0; i < candies.size(); i++)
        {ans.push_back(candies[i] + extraCandies >= maxi);}
        return ans;
        
    }
};
