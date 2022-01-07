/*
https://leetcode.com/problems/string-matching-in-an-array/
*/

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        
        vector<string> ans;
        vector<int> flag(words.size(), 1);
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(words[i].length() >= words[j].length())
                {
                    if(flag[j] && words[i].find(words[j]) != string::npos) 
                    {
                        ans.push_back(words[j]);
                        flag[j] = 0;
                    }
                }
                else
                {
                    if(flag[i] && words[j].find(words[i]) != string::npos) 
                    {
                        ans.push_back(words[i]);
                        flag[i] = 0;
                    }
                }
            }
        }
        return ans;
    }
};
