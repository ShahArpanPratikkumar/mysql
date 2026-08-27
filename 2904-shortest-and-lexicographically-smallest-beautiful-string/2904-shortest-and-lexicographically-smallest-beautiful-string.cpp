class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        string ans = "";
        
        for (int i = 0; i < n; ++i) {
            int countOnes = 0;
            for (int j = i; j < n; ++j) {
                if (s[j] == '1') {
                    countOnes++;
                }
                
                if (countOnes == k) {
                    string sub = s.substr(i, j - i + 1);
                    if (ans.empty() || sub.length() < ans.length() || 
                       (sub.length() == ans.length() && sub < ans)) {
                        ans = sub;
                    }
                    break; // Moving j further will only increase length with countOnes >= k
                }
            }
        }
        
        return ans;
    }
};