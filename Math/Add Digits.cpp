/*
https://leetcode.com/problems/add-digits/
*/

class Solution {
public:
    int addDigits(int num) {
        if (!num) return num;
        return num % 9 ? num % 9 : 9;
    }
};
