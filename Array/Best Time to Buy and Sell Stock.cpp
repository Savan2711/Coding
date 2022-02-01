/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/* Using two pointers (i.e., buy and sell) */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0, buy = 0, sell = 1;
        while(buy < prices.size() - 1 && sell < prices.size())
        {
            profit = max(profit, prices[sell] - prices[buy]);
            if(prices[sell] < prices[buy])
            {buy = sell;}
            sell++;
        }
        return profit;
        
    }
};

/* Using Kadane's algorithm */
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
