/*
https://leetcode.com/problems/second-largest-digit-in-a-string/
*/

class Solution {
public:
    int secondHighest(string s) {
        
        int slar = -1, lar = -1;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9')
            {
                if(s[i] - '0' > lar)
                {
                    slar = lar;
                    lar = s[i] - '0';
                }
                else if(s[i] - '0' < lar && s[i] - '0' > slar)
                {
                    slar = s[i] - '0';
                }
            }
        }
        if(lar == slar) return -1;
        return slar;
    }
};
