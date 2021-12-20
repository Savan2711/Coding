/*
https://leetcode.com/problems/excel-sheet-column-title/
*/

class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string ans = "";
        while(columnNumber)
        {
            ans += (char)(65 + (((columnNumber % 26) - 1) >= 0 ? ((columnNumber % 26) - 1) : 25));
            columnNumber -= ( (columnNumber % 26) == 0 ? 26 : (columnNumber % 26) );
            columnNumber /= 26;
        }
        
        return string(ans.rbegin(), ans.rend());
    }
};
