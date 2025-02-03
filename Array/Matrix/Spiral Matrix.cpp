/*
https://leetcode.com/problems/spiral-matrix/description/
*/

class Solution {
public:
    vector<int> ans;
    void spiral(vector<vector<int>>& matrix, int m, int n, int r, int c, int dr, int dc) {
        if(m == 0 || n == 0) return;
        for(int i = 0; i < n; i++) {
            r += dr;
            c += dc;
            ans.push_back(matrix[r][c]);
        }
        spiral(matrix, n, m - 1, r, c, dc, -dr);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        spiral(matrix, matrix.size(), matrix[0].size(), 0, -1, 0, 1);
        return ans;
    }
};
