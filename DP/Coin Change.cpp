/*
https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    
        if(amount == 0)
        {return 0;}
        
        int nC = coins.size();
        
        
        int dp[nC + 1][amount + 1];
        
        for(int i = 0; i <= nC; i++)
        {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= amount; i++)
        {
            dp[0][i] = 100000;
        }
        
        for(int i = 1; i <= nC; i++)
        {
            for(int j = 1; j <= amount; j++)
            {
                if(j % coins[i - 1] == 0)
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }
                else
                {
                    if(j - coins[i - 1] < 0)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]); 
                    }
                }    
            }
        }
        
        return dp[nC][amount] >= 100000 ? -1 : dp[nC][amount];
    }
};