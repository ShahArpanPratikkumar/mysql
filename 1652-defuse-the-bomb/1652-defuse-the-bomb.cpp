class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if (k == 0) return result;

        // Window boundaries setup
        int left = 1, right = k;
        if (k < 0) {
            left = n + k;
            right = n - 1;
        }

        // Initial window sum calculation
        int currentSum = 0;
        for (int i = left; i <= right; ++i) {
            currentSum += code[i];
        }

        // Sliding window across circular array
        for (int i = 0; i < n; ++i) {
            result[i] = currentSum;
            currentSum -= code[left % n];
            currentSum += code[(right + 1) % n];
            left++;
            right++;
        }

        return result;
    }
};