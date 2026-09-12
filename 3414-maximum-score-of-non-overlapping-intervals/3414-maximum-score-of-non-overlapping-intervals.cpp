#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
        bool operator<(const Interval& other) const {
            if (l != other.l) return l < other.l;
            if (r != other.r) return r < other.r;
            return id < other.id;
        }
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = {intervals[i][0], intervals[i][1], intervals[i][2], i};
        }
        sort(a.begin(), a.end());

        // Array of left boundaries for binary search
        vector<int> starts(n);
        for (int i = 0; i < n; ++i) {
            starts[i] = a[i].l;
        }

        // dp[i][k] stores {max_weight, list_of_chosen_original_indices}
        vector<vector<pair<long long, vector<int>>>> dp(n + 1, vector<pair<long long, vector<int>>>(5, {0, {}}));

        for (int i = n - 1; i >= 0; --i) {
            // Find first interval starting strictly after current interval ends (a[i].r)
            int nxt = upper_bound(starts.begin(), starts.end(), a[i].r) - starts.begin();

            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip interval i
                auto best = dp[i + 1][k];

                // Option 2: Take interval i
                long long take_weight = a[i].weight + dp[nxt][k - 1].first;
                
                // Form candidates list
                vector<int> take_indices = {a[i].id};
                take_indices.insert(take_indices.end(), dp[nxt][k - 1].second.begin(), dp[nxt][k - 1].second.end());

                pair<long long, vector<int>> take_cand = {take_weight, take_indices};

                // Compare candidates
                if (take_cand.first > best.first) {
                    best = take_cand;
                } else if (take_cand.first == best.first && take_cand.first > 0) {
                    // Create sorted versions of indices to properly compare lexicographically
                    vector<int> cand_sorted = take_cand.second;
                    vector<int> best_sorted = best.second;
                    sort(cand_sorted.begin(), cand_sorted.end());
                    sort(best_sorted.begin(), best_sorted.end());

                    if (best_sorted.empty() || cand_sorted < best_sorted) {
                        best = take_cand;
                    }
                }

                dp[i][k] = best;
            }
        }

        vector<int> res = dp[0][4].second;
        sort(res.begin(), res.end());
        return res;
    }
};