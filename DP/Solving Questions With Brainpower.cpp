/*
https://leetcode.com/problems/solving-questions-with-brainpower/
*/

/* Using DP */
class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int nQue = questions.size();
        vector<long long int> dp(nQue, 0);
        
        dp[nQue - 1] = questions[nQue - 1][0]; 
        long long int ans = dp[nQue - 1];
        
        for(int i = nQue - 2; i >= 0; i--)
        {
            if(i + questions[i][1] + 1 >= nQue)
            {
                dp[i] = max((long long int)questions[i][0], dp[i + 1]);
            }
            else
            {
                dp[i] = max((long long int)questions[i][0] + dp[i + questions[i][1] + 1], dp[i + 1]);
            }
            ans = max(ans, dp[i]);
        }
        
        return ans;
        
    }
};
