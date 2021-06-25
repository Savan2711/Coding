/*
https://leetcode.com/problems/fibonacci-number/
*/

class Solution {
public:
    int fib(int n) {
        
        int a = 0, b = 1;
        if(n == 0)
        {return a;}
        else if(n == 1)
        {return b;}
        
        for(int i = 2; i <= n; i++)
        {
            b += a;
            a = b - a;
        }
        
        return b;
        
    }
};