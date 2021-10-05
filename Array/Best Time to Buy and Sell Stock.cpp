/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int b = INT_MAX, profit = 0;
        for(int  i = 0; i < prices.size(); i++)
        {
            if(b > prices[i]) b = prices[i];
            
            profit = max(profit, prices[i] - b);
        }
        
        return profit;   
    }
};