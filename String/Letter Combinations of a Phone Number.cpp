/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        unordered_map<int, string> umap;
        char ch = 'a';
        vector<string> ans;
        
        if(!digits.size()) return ans;
        
        for(int i = 2; i <= 9; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                umap[i].push_back(ch);
                ch++;
            }
            if(i == 7 || i == 9)
            {
                umap[i].push_back(ch);
                ch++;
            }
        }
        
        ans.push_back("");
        for(char ch : digits)
        {
            ch -= '0';
            vector<string> temp;
            
            for(auto st : ans)
            {
                for(auto it : umap[ch])
                {
                    string str = st + it;
                    temp.push_back(str);
                }
            }
            ans = temp;
        }
        
        return ans;
        
    }
};
