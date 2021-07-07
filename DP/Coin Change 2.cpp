/*
https://leetcode.com/problems/coin-change-2/
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));
        
        for(int i = 1; i <= amount; i++)
        {
            dp[0][i] = i % coins[0] ? 0 : 1; 
        }
        
        for(int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 1; 
        }
        
        for(int i = 1; i < coins.size(); i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j - coins[i] < 0)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];  
                }
            }
        }
        
        return dp[coins.size() - 1][amount];
    }
};