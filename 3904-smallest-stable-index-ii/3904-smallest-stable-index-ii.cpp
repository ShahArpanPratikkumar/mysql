class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return -1;

        // Precompute suffix minimums
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        // Compute prefix maximum on the fly and check condition
        int prefMax = nums[0];
        for (int i = 0; i < n; ++i) {
            prefMax = max(prefMax, nums[i]);
            
            // Instability score: max(nums[0..i]) - min(nums[i..n-1])
            if (prefMax - suffMin[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};