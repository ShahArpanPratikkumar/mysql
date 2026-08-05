class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        int n = word.length();
        
        for (char c : word) {
            if (isupper(c)) {
                capCount++;
            }
        }
        
        if (capCount == n || capCount == 0) {
            return true;
        }
        
       
        if (capCount == 1 && isupper(word[0])) {
            return true;
        }
        
        return false;
    }
};