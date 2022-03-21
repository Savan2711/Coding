/*
https://leetcode.com/problems/partition-labels/
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        vector<int> lastInd(26, -1);
        
        for(int i = 0; i < s.length(); i++)
        {
            lastInd[s[i] - 'a'] = i;
        }
        
        int si = 0, li = lastInd[s[0] - 'a'];
        while(li != s.length() - 1)
        {
            int temp = li;
            while(temp > si)
            {
                if(lastInd[s[temp] - 'a'] > li)
                {
                    li = lastInd[s[temp] - 'a'];
                    break;
                }
                temp--;
            }
            if(temp == si) 
            {
                ans.push_back(li - si + 1);
                si = li + 1;
                li = lastInd[s[si] - 'a'];
            }
        }
        ans.push_back(li - si + 1);
        
        return ans;
    }
};
