/*
https://leetcode.com/problems/permutation-in-string/
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        if(s1.length() > s2.length()) return false;
            
        vector<int> freq_s1(26, 0);
        vector<int> freq_s2(26, 0);
        
        int i = 0, j = 0;
        for(int i = 0; i < s1.length(); i++)
        {freq_s1[s1[i] - 'a']++;}
        
        i = 0; j = 0;
        while(i <= j && j < s2.length())
        {
            if(!freq_s1[s2[j] - 'a'])
            {
                fill(freq_s2.begin(), freq_s2.end(), 0);
                j++;
                i = j;
                continue;
            }
            
            freq_s2[s2[j] - 'a']++;
            while(i <= j && freq_s1[s2[j] - 'a'] < freq_s2[s2[j] - 'a'])
            {
                freq_s2[s2[i] - 'a']--;
                i++;
            }
            
            int k;
            for(k = 0; k < 26; k++)
            {
                if(freq_s1[k] > freq_s2[k])
                {
                    break;
                }
            }
            if(k == 26) return true;
            
            j++;
            
        }
        
        return false;
    
    }
};
