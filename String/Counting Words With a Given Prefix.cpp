/*
https://leetcode.com/problems/counting-words-with-a-given-prefix/
*/

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (auto str : words) {
            ans++;
            for(int j = 0; j < pref.length(); j++) {
                if(str[j] != pref[j]) {
                    ans--;
                    break;
                }
            } 
        }
        return ans;
    }
};
