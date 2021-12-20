/*
https://leetcode.com/problems/excel-sheet-column-number/
*/

class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int ans = 0, len = columnTitle.length();
        for(int i = len - 1; i >= 0; i--)
        {
            ans += (columnTitle[i] - 'A' + 1) * pow(26, len - 1 - i); 
        } 
        return ans;
    }
};

