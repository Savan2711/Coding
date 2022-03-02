/*
https://leetcode.com/problems/is-subsequence/
*/

/* DP solution */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int l1 = s.length();
        int l2 = t.length(); 
        bool dp[l1 + 1][l2 + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for(int i = 0; i <= l2; i++)
        {
            dp[0][i] = true;
        }
        for(int i = 1; i <=  l1; i++)
        {
            for(int j = 1; j <= l2; j++)
            {
                if(dp[i][j - 1] && dp[i - 1][j])
                {
                    dp[i][j] = true;
                }
                else if(s[i - 1] == t[j - 1] && dp[i - 1][j] && dp[i - 1][j - 1])
                {
                    dp[i][j] = true;
                }
                cout << dp[i][j] <<  " ";
            }
            cout << endl;
        }
        return dp[l1][l2];
    }
};

/* Two pointer solution - Better - 0ms  */
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int sPtr = 0, tPtr = 0;
        while(sPtr < s.length() && tPtr < t.length())
        {
            if(s[sPtr] == t[tPtr])
            {
                sPtr++;
            }
            tPtr++;
        }
        return sPtr == s.length();
        
    }
};
