/*
https://leetcode.com/problems/maximum-score-from-removing-stones/
*/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        
        vector<int> vc = {a, b, c};
        
        sort(vc.begin(), vc.end());
        
        int sum = vc[0] + vc[1], ans = 0;
        
        if(sum <= vc[2])
        {
            return sum;
        }
        else
        {
            while(sum > vc[2])
            {
                sum -=2;
                ans++;
            }
            ans += sum;
        }
        
        return ans;
    }
};
