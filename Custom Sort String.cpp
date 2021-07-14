/*
https://leetcode.com/problems/custom-sort-string/
*/
class Solution {
public:
    string customSortString(string order, string str) {
        
        unordered_map<char, int> umap;
        
        for(int i = 0; i < str.length(); i++)
        {
            umap[str[i]]++;
        }
        
        string ans = "";
        for(int i = 0; i < order.length(); i++)
        {
            if(umap.count(order[i]))
            {
                for(int j = 0; j < umap[order[i]]; j++)
                {ans += order[i];}
                umap.erase(order[i]);
            }
        }
        
        for(auto it : umap)
        {
            for(int j = 0; j < it.second; j++)
            {ans += (it.first);}
            
        }
        
        return ans;
    }
};