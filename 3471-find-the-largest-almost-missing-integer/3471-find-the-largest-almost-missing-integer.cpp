class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        // Count frequencies of elements in each subarray of size k
        for (int i = 0; i <= n - k; ++i) {
            unordered_set<int> unique_in_subarray(nums.begin() + i, nums.begin() + i + k);
            for (int num : unique_in_subarray) {
                freq[num]++;
            }
        }

        int ans = -1;
        // Find the maximum value that appears in exactly 1 subarray
        for (auto& [num, count] : freq) {
            if (count == 1) {
                ans = max(ans, num);
            }
        }

        return ans;
    }
};