/*
https://leetcode.com/problems/boats-to-save-people/
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());
        
        int l = 0, h = people.size() - 1, res = 0;
        while(l <= h)
        {
            if(people[l] + people[h] <= limit)
            {
                l++;
            }
            h--;
            res++;
        }
        
        return res;
        
    }
};
