/*
https://leetcode.com/problems/2-keys-keyboard/
*/

class Solution {
public:
    
    vector<int> dp = vector<int>(1001, 0);
    
    Solution()
    {
        dp[1] = 0;
        dp[2] = 2;
        dp[3] = 3;
        
        for(int i = 4; i <= 1000; i++)
        {
            if(!(i & 1))
            {
                dp[i] = dp[i / 2] + 2;
            }
            else
            {
                int t = primeLike(i);
                if(t == -1)
                {dp[i] = i;}
                else
                {
                    dp[i] = dp[t] + (i / t);
                }
            }
        }
    }
    
        
    
    int primeLike(int n)
    {
        for(int i = 2; i * i <= n; i++)
        {
            if(n % i == 0)
            {
                return n / i;
            }
        }
        return -1;
    }
    
    
    int minSteps(int n) {
        
        return dp[n];
        
    }
};
