class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int, int> prefix;
        prefix[0] = -1;
        
        vector<int> min_len(n, INT_MAX);
        int sum = 0, best_len = INT_MAX, ans = INT_MAX;

        for (int i = 0; i < n; ++i) {
            sum += arr[i];
            
            if (prefix.count(sum - target)) {
                int prev_idx = prefix[sum - target];
                int len = i - prev_idx;

                if (prev_idx >= 0 && min_len[prev_idx] != INT_MAX) {
                    ans = min(ans, len + min_len[prev_idx]);
                }
                best_len = min(best_len, len);
            }

            min_len[i] = best_len;
            prefix[sum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};