/*
https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
*/

class Solution {
public:
    int minSwaps(string s) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int cnt = 0, ans = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ']')
            {
                if(cnt == 0)
                {
                    cnt++;
                    ans++;
                }
                else
                {
                    cnt--;
                }
            }
            else
            {cnt++;}
        }
        return ans;
    }
};

