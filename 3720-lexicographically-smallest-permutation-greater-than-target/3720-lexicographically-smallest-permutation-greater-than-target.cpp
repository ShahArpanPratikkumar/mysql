class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Try to match prefix of target of length `L` (from n down to 0)
        vector<int> prefix_count = count;
        
        // Track frequency availability as we match target characters
        for (int L = 0; L <= n; ++L) {
            // Check if we can form a prefix matching target[0...L-1]
            // We evaluate backwards from longest prefix to shortest
        }

        // Alternative efficient construction:
        // 1. Count frequencies of `s`
        // 2. Walk along `target` as far as possible while frequencies allow.
        // 3. From the deepest possible index `i`, try placing a character > target[i],
        //    then fill the rest with sorted remaining characters.

        // Store original character counts
        vector<int> orig_count(26, 0);
        for (char c : s) orig_count[c - 'a']++;

        // Try to match target up to length L, then make (L)-th char strictly greater
        for (int L = n - 1; L >= 0; --L) {
            vector<int> freq = orig_count;
            bool possible = true;

            // Check if target[0...L-1] can be formed
            for (int i = 0; i < L; ++i) {
                if (--freq[target[i] - 'a'] < 0) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;

            // Find smallest character strictly greater than target[L]
            int diff_char = -1;
            for (int c = target[L] - 'a' + 1; c < 26; ++c) {
                if (freq[c] > 0) {
                    diff_char = c;
                    break;
                }
            }

            if (diff_char != -1) {
                // Build the answer string
                string result = target.substr(0, L);
                result.push_back('a' + diff_char);
                freq[diff_char]--;

                // Append remaining characters in ascending order
                for (int c = 0; c < 26; ++c) {
                    while (freq[c] > 0) {
                        result.push_back('a' + c);
                        freq[c]--;
                    }
                }
                return result;
            }
        }

        return "";
    }
};