/*
https://leetcode.com/problems/n-th-tribonacci-number/
*/

class Solution {
public:
    int tribonacci(int n) {
       
        int a = 0, b = 1, c = 1;
        if(n == 0 || n == 1)
        {return n;}
        if(n == 2)
        {return c;}
        
        for(int i = 3; i <= n; i++)
        {
            c += a + b;
            b = c - a - b;
            a = c - b - a;
            // cout << a << " " << b << " " << c << endl;
        }
        
        return c;
        
    }
};