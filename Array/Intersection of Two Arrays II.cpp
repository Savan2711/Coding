/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

class Solution {
public:
    vector<int> intersect(vector<int>& num1, vector<int>& num2) {
        
        if(num1.size() > num2.size()) return intersect(num2, num1);
        
        unordered_map<int, int> umap;
        
        for(int i = 0; i < num1.size(); i++)
        {
            umap[num1[i]]++;
        }
        
        vector<int> ans;
        for(int i = 0; i < num2.size(); i++)
        {
            // cout << umap.count(num2[i]) << " ";
            if(umap[num2[i]] != 0)
            {
                umap[num2[i]]--;
                ans.push_back(num2[i]);
            }
        }
        
        return ans;
    }
};