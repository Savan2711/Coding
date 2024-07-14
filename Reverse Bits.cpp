/*
https://leetcode.com/problems/reverse-bits/description/
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t multiplier = pow(2, 31), ans = 0;
        while(n) {
            ans += multiplier * (n % 2);
            n /= 2;
            multiplier /= 2;
        }
        return ans;
    }
};
