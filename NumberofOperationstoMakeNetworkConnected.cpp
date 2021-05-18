/*
https://leetcode.com/problems/number-of-operations-to-make-network-connected/
*/

class Solution {
public:
    
    void bfs(int src, vector<vector<int>>& connections, vector<int>& visited)
    {
        deque<int> q;
        q.push_back(src);
        
        while(!q.empty())
        {
            int u = q.front();
            q.pop_front();
            for(int i = 0; i < connections[u].size(); i++)
            {
                if(!visited[connections[u][i]])
                {
                    visited[connections[u][i]] = 1;
                    q.push_back(connections[u][i]);
                }
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
        {return -1;}
        
        int ans = 0;
        
        vector<vector<int>> pass(n);
        for(int i = 0; i < connections.size(); i++)
        {            
            pass[connections[i][0]].push_back(connections[i][1]);
            pass[connections[i][1]].push_back(connections[i][0]);
        }
        
        
        vector<int> v(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            if(!v[i])
            {
                bfs(i, pass, v);                
                ans++;
            }
        }
        
        return ans - 1;
        
    }
};