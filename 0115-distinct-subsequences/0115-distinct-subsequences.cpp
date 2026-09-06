class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // If s is shorter than t, t cannot be a subsequence of s
        if (n < m) return 0;
        
        // dp[j] stores the number of subsequences matching t[0...j-1]
        // Using unsigned long long to prevent integer overflow during intermediate states
        vector<unsigned long long> dp(m + 1, 0);
        
        // Base case: empty t can be formed in 1 way
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = m; j >= 1; --j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        
        return dp[m];
    }
};