/*
https://leetcode.com/problems/count-the-number-of-consistent-strings/
*/

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        ios::sync_with_stdio(false);
        cin.tie(0);
        
        bool trace[27] = {false};
        
        for(int i = 0; i < allowed.length(); i++)
        {
            trace[allowed[i] - 'a'] = true;
        }
        
        int ans = 0;
        
        for(auto it : words)
        {
            ans++;
            for(int i = 0; i < it.length(); i++)
            {
                if(!trace[it[i] - 'a'])
                {
                    ans--;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};
