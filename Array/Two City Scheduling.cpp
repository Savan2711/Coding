/*
https://leetcode.com/problems/two-city-scheduling/
*/

class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b)
    {
        return abs(a[0] - a[1]) <= abs(b[0] - b[1]);
    }
    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int n = costs.size();
        
        int first = 0, second = 0, ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(costs[i][0] <= costs[i][1])
            {
                first++;
                ans += costs[i][0];
            }
            else
            {
                second++;
                ans += costs[i][1];
            }
        }
        
        if(first == second) return ans;
        
        sort(costs.begin(), costs.end(), compare);
        
        int i = 0;
        while(first > second)
        {
            if(costs[i][0] <= costs[i][1])
            {
                first--;
                second++;
                ans += (costs[i][1] - costs[i][0]);
            }
            i++;
        }
        
        i = 0;
        while(first < second)
        {
            if(costs[i][0] > costs[i][1])
            {
                first++;
                second--;
                ans += (costs[i][0] - costs[i][1]);
            }
            i++;
        }
        
        return ans;
    }
};
