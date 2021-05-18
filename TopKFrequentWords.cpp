/*
https://leetcode.com/problems/top-k-frequent-words/

Solution :
Time : O(n*log(k))
Space : O(n)
*/

class Solution {
public:
    
    struct cmp
    {
        bool operator()(pair<string, int> &a, pair<string, int> &b)
        {
            if(a.second > b.second)
            {
                return true;
            }
            else if(a.second < b.second)
            {
                return false;
            }

            return (b.first).compare(a.first) > 0 ? true : false;

        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string, int> umap;
        int n = words.size();
        
        vector<string> ans;
        
        for(int i = 0; i < n; i++)
        {
            umap[words[i]]++;
        }
        
        priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
        
        for(auto it : umap)
        {
            pq.push({it.first, it.second});
            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};