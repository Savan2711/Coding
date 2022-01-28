/*
https://leetcode.com/problems/count-vowel-substrings-of-a-string/
*/

class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
        {return true;}
        return false;
    }
    
    int countVowelSubstrings(string word) {
        
        if(word.length() < 5) return 0;
        
        int start, end, ans = 0;
        set<char> st;
        for(int i = 0; i < word.length() - 4; i++)
        {
            for(int j = i; j < word.length(); j++)
            {
                if(!isVowel(word[j]))
                {
                    st.clear();
                    break;
                }
                
                st.insert(word[j]);
                if(st.size() == 5) ans++;
                
            }
            
            st.clear();
        }
        return ans;
        
    }
};
