/*
https://leetcode.com/problems/angle-between-hands-of-a-clock/submissions/
*/

class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double mAngle = (minutes / 60.0) * 360;
        
        int temp = hour == 12 ? 0 : hour;
        double hAngle = (temp * 30) + (minutes / 60.0) * 30;
        
        return min(360 - abs(mAngle - hAngle), abs(mAngle - hAngle));
        
    }
};