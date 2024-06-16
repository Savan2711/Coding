/*
https://leetcode.com/problems/pascals-triangle-ii/description/
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        int i = rowIndex - 1;
        ans[rowIndex] = 1;
        while(i >= 0) {
            for (int k = i; k < rowIndex; k++) {
                ans[k] += ans[k + 1];
            }
            i--;
        }
        return ans;
    }
};
