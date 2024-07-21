/*
https://leetcode.com/problems/reconstruct-a-2-row-binary-matrix/description/
*/

class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        vector<vector<int>> ans(2, vector<int>(colsum.size(), 0));
        vector<int> rowsum = {upper, lower};
        
        for (int j = 0; j < colsum.size(); j++) {
            if (!colsum[j]) {continue;}

            if(colsum[j] == 2) {
                ans[0][j] = 1;
                ans[1][j] = 1;
                colsum[j] = 0;
                upper -= 1;
                lower -= 1;
            }
            else if(colsum[j] == 1) {
                if(upper >= lower) {
                    ans[0][j] = 1;
                    upper -= 1;
                } else {
                    ans[1][j] = 1;
                    lower -= 1;
                }
            } 
        }
        
        if(upper != 0 || lower != 0) return {};

        return ans;    
    }
};
