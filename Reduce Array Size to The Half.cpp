/*
https://leetcode.com/problems/reduce-array-size-to-the-half/
*/

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b)
    {
        return a.second > b.second;    
    }
    
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> umap;
        
        for(int i = 0; i < arr.size(); i++)
        {
            umap[arr[i]]++;
        }
        
        vector<pair<int, int>> vec(umap.begin(), umap.end());
        
        sort(vec.begin(), vec.end(), cmp);
        
        int ans = 0, cnt = 0;
        for(auto& it : vec)
        {
            cnt += it.second;
            ans++;
            // cout << cnt << " ";   
            if(cnt >= (arr.size() / 2))
            {break;}
        }
        
        return ans;
    }
};