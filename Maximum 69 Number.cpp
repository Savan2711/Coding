/*
https://leetcode.com/problems/maximum-69-number/
*/

class Solution {
public:
    int maximum69Number (int num) {
        
        int startWith = 1000, ans = 0, flag = 1;
        while(startWith > 0)
        {
            if(startWith < num)
            {
                int tmp = num / startWith;
                if(tmp == 6 && flag)
                {ans += (9 * startWith); flag = 0;}
                else
                {
                    ans += (num - (num % startWith));
                }
                num = num % startWith;
            }
            startWith /= 10;
        }
        return ans;
    }
};