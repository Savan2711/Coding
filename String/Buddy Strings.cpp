/*
https://leetcode.com/problems/buddy-strings/
*/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        if(s.length() != goal.length()) return false;
        
        int cnt = 0;
        vector<int> vec;
        unordered_map<char, int> umap1;
        for(int i = 0; i < s.length(); i++)
        {
            if(cnt > 2) return false;
            
            umap1[s[i]]++;
            
            if(s[i] != goal[i])
            {
                vec.push_back(i);
                cnt++;
            }
        }
        
        if(cnt == 0)
        {
            for(auto it : umap1)
            {
                if(it.second >= 2) return true;
            }
            return false;
        }
        if(cnt == 2)
        {
            if((s[vec[0]] == goal[vec[1]]) && (s[vec[1]] == goal[vec[0]]))
            {return true;}
        }
        return false;
    }
};
