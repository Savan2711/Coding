/*
https://leetcode.com/problems/maximum-score-after-splitting-a-string/
*/

class Solution {
public:
    int maxScore(string s) {
        
        int len = s.length(), i = 1;
        vector<int> freqz(len, 0);
        vector<int> freqo(len, 0);
        
        if(s[0] == '0') 
        {freqz[0]++;}
          
        while(i < len - 1)
        {
            if(s[i] == '0')
            {
                freqz[i] += freqz[i - 1] + 1;
            }
            else
            {
                freqz[i] += freqz[i -1];
            }
            i++;
        }
        
        i = len - 2;
        while(i >= 0)
        {
            if(s[i + 1] == '1')
            {
                freqo[i] += (freqo[i + 1] + 1);
            }
            else
            {
                freqo[i] += freqo[i + 1];
            }
            i--;
        }
    
        int ans = INT_MIN;
        for(int i = 0; i < freqz.size(); i++)
        {
            if(freqz[i] + freqo[i] > ans)
            {
                ans = freqz[i] + freqo[i];
            }
        }
        return ans;
    }
};

