/*
https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/
*/

class Solution {
public:
    string generateTheString(int n) {
        string ans(n, 'a');
        if(!(n & 1)) ans[0] = 'b';
        return ans;
    }
};
