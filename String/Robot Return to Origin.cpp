/*
https://leetcode.com/problems/robot-return-to-origin/
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        
        ios::sync_with_stdio(0); 
        cin.tie(0);
        
        int len = moves.length();
        if(len % 2) return false;
        
        int UDcnt = 0, LRcnt = 0;
        for(int i = 0; i < len; i++)
        {
            if(moves[i] == 'U') UDcnt++;
            else if(moves[i] == 'D') UDcnt--;
            else if(moves[i] == 'L') LRcnt++;
            else LRcnt--;
        }
        
        return UDcnt == 0 && LRcnt == 0;
        
    }
};
