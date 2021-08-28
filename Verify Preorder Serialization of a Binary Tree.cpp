/*
https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
      
        if(!preorder.length()) return false;
        int count = 1;
        
        stringstream check1(preorder);
        
        vector<string> tokens;
        
        string intermediate;
        while(getline(check1, intermediate, ','))
        {
            tokens.push_back(intermediate);
        }
        
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] != "#")
            {
                count++;
            }
            else count--;
            
            if(count == 0 && i != tokens.size() - 1) return false;
        }
        
        if(count) return false;
        return true;
        
    }