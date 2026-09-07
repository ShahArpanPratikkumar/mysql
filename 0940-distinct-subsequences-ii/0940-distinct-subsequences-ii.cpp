class Solution {
public:
    int distinctSubseqII(string s) {
        long MOD = 1e9 + 7;
        long total = 0;
        vector<long> dp(26, 0); // Stores count of distinct subsequences ending at each char
        
        for (char c : s) {
            int idx = c - 'a';
            long new_seq = (total + 1 - dp[idx] + MOD) % MOD;
            
            total = (total + new_seq) % MOD;
            dp[idx] = (dp[idx] + new_seq) % MOD;
        }
        
        return total;
    }
};