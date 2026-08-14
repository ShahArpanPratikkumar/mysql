class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        
        for (int i = 0; i < n; ++i) {
            vector<int> count(26, 0);
            for (int j = i; j < n; ++j) {
                count[s[j] - 'a']++;
                
                if (count[s[j] - 'a'] > 2) {
                    break; // Invalid substring, stop expanding right pointer
                }
                
                maxLength = max(maxLength, j - i + 1);
            }
        }
        
        return maxLength;
    }
};