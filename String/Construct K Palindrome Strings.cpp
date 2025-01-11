/*
https://leetcode.com/problems/construct-k-palindrome-strings/
*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) {return false;}
        vector<int> count(26, 0);
        int oddCount = 0; 
        for(int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            oddCount += count[i] & 1;
        }

        return oddCount <= k;
    }
};
