/*
https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/
*/

class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int one = 0, zero = 0, maxZero = INT_MIN, maxOne = INT_MIN;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '0')
            {
                zero++;
                one = 0;
            }
            else
            {
                one++;
                zero = 0;
            }
            if(maxZero < zero) maxZero = zero;
            if(maxOne < one) maxOne = one;
        }
        return maxOne > maxZero;
    }
};
