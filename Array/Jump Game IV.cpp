/*
https://leetcode.com/problems/jump-game-iv/
*/

/* Solution using BFS */

class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        if(arr.size() == 1) return 0;
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        unordered_map<int, vector<int>> umap;
        int n = arr.size();
        for(int i = 0; i < n; i++)
        {
            umap[arr[i]].push_back(i);
        }
        
        vector<int> visited(n, 0);
        vector<int> depth(n, 0);
        
        deque<int> q;
        q.push_back(0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int cur = q.front();
            q.pop_front();
            
            if(cur == n - 1) return depth[cur];
            
            for(auto it : umap[arr[cur]])
            {
                if(!visited[it])
                {
                    q.push_back(it);
                    visited[it] = 1;
                    depth[it] = depth[cur] + 1;
                }
            }
            if(cur > 0 && !visited[cur - 1]) 
            {
                q.push_back(cur - 1);
                visited[cur - 1] = 1;
                depth[cur - 1] = depth[cur] + 1;  
            }
            if(cur < n - 1 && !visited[cur + 1])
            {
                q.push_back(cur + 1);
                visited[cur + 1] = 1;
                depth[cur + 1] = depth[cur] + 1;
            }
            umap.erase(arr[cur]);
        }
        
        return 0;
        
    }
};
