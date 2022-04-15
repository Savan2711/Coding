/*
https://leetcode.com/problems/number-of-islands/
*/

class Solution {
public:
    
    vector<vector<int>> dir{{0, 1}, {-1, 0}, {1, 0}, {0, -1}};
    void helper(vector<vector<char>>& grid, int i , int j)
    {
        if(grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        for(int k = 0; k < 4; k++)
        {
            int ni = dir[k][0] + i;
            int nj = dir[k][1] + j;
            
            if(ni < 0 || nj < 0 || ni >= grid.size() || nj >= grid[0].size() || grid[ni][nj] == '0')
            {continue;}
            
            helper(grid, ni, nj);
            
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    helper(grid, i , j);
                }
            }
        }
        
        return ans;
        
    }
};
