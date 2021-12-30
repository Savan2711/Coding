/*
https://leetcode.com/problems/implement-strstr/

Solution: 
	KMP string matching algorithm.
	O(m) to generate lps array and O(n) for searching ---> O(m + n) ---> O(n)
	The time complexity of KMP algorithm is O(n) in the worst case.
*/

class Solution {
public:
    
    void buildLPS(string needle, vector<int> &lps)
    {
        int len = 0, i = 1;
        
        lps[0] = 0;
        
        while(i < needle.length())
        {
            if(needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
                else
                {
                    len = lps[len - 1];
                }
            }
        }
    }
    
    int KMPSearch(string s, string pat)
    {
        int N = s.length(), M = pat.length();
        
        if(M == 0) return 0;
        
        vector<int> lps(pat.length());
        
        buildLPS(pat, lps);
        
        int i = 0, j = 0;
        while (i < N) 
        {
            if (pat[j] == s[i]) 
            {
                j++;
                i++;
            }

            if (j == M) 
            {
                return i - j;
            }
            else if (i < N && pat[j] != s[i]) 
            {
                if (j != 0)
                {j = lps[j - 1];}
                else
                {i = i + 1;}
            }
        }
        return -1;
    }
    
    int strStr(string haystack, string needle) {
        return KMPSearch(haystack, needle);
    }
};
