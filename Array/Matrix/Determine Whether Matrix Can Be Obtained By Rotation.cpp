/*
https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/description/
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i; j < matrix[i].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }

    bool equal(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < mat.size(); i++) {
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(equal(mat, target)) return true;
        rotate(mat);
        if(equal(mat, target)) return true;
        rotate(mat);
        if(equal(mat, target)) return true;
        rotate(mat);
        if(equal(mat, target)) return true;
        return false;
    }
};
