/*
https://leetcode.com/problems/unique-substrings-in-wraparound-string/
*/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        
        int ln = p.length();
        
        if(ln == 1) return 1;
        
        vector<int> trace(26, 0);
        
        int i = 0, j = 1, subln = 1, ans = 0;
        trace[p[i] - 'a'] = 1;
        while(i < ln - 1 && j < ln)
        {
            if((p[j] - p[i] == 1) || (p[i] - p[j] == 25))
            {
                subln++;
            }
            else
            {
                subln = 1;
            }
            if(trace[p[j] - 'a'] < subln) 
            {trace[p[j] - 'a'] = subln;}
            i++;
            j++;
        }
        
        for(int i = 0; i < 26; i++)
        {
            ans += trace[i];
        }
        
        return ans;
        
    }
};

