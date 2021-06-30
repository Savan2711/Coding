/*
https://leetcode.com/problems/champagne-tower/
*/

class Solution {
public:
    
    double dp[101][101];
    
    double dpFun(int r, int c, int p)
    {
        if(r == 0 && c == 0) return p;
        if(r < 0 || c < 0) return 0;
        if(r < c) return 0;
        
        if(dp[r][c] > -1) return dp[r][c];  
        
        double left = dpFun(r - 1, c - 1, p);
        double right = dpFun(r - 1, c, p);
        
        double l = 0, h = 0;
        if(left > 1)
        {l = (left - 1) / 2;}
        if(right > 1)
        {h = (right - 1) / 2;}
        
        dp[r][c] = l + h;
        return l + h;
        
    }
    
    double champagneTower(int poured, int query_row, int query_glass) {
        
        memset(dp, -1, sizeof(dp));
        
        if(!poured) return 0;
        
        double ans = dpFun(query_row, query_glass, poured);
        
        return ans > 1 ? 1 : ans;
    }
};