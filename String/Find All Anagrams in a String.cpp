/*
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;
        int sfreq[26] = {0}, pfreq[26] = {0};
        int slen = s.length(), plen = p.length(), i = 0;
        
        if(slen < plen) return ans;
        
        for(i = 0; i < plen; i++)
        {
            sfreq[s[i] - 'a']++;
            pfreq[p[i] - 'a']++;
        }
        
        for(i = 0; i < 26; i++)
        {
            if(sfreq[i] != pfreq[i]) break;
        }
        if(i == 26) ans.push_back(0);
        
        for(i = plen; i < slen; i++)
        {
            sfreq[s[i - plen] - 'a']--;
            sfreq[s[i] - 'a']++;
            int j;
            for(j = 0; j < 26; j++)
            {
                if(sfreq[j] != pfreq[j]) break;
            }
            if(j == 26) ans.push_back(i - plen + 1);
        }
        return ans;
        
    }
};
