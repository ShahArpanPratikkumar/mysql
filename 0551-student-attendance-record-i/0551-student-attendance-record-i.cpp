class Solution {
public:
    bool checkRecord(string s) {
        int absCount = 0;
        int lateCount = 0;

        for (char c : s) {
            if (c == 'A') {
                absCount++;
                lateCount = 0; 
                if (absCount >= 2) return false;
            } else if (c == 'L') {
                lateCount++;
                if (lateCount >= 3) return false;
            } else {
                lateCount = 0; 
            }
        }

        return true;
    }
};