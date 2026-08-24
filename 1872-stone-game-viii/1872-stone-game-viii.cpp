class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        
        // Compute prefix sums in-place
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }
        
        // Base case: max score difference starting from the last valid state
        int maxDiff = stones[n - 1];
        
        // Process backward from the second-to-last element down to index 1 (at least 2 stones taken)
        for (int i = n - 2; i >= 1; i--) {
            maxDiff = max(maxDiff, stones[i] - maxDiff);
        }
        
        return maxDiff;
    }
};