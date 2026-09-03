class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int min_val = INT_MAX;
        bool has_odd = false;

        for (int num : nums1) {
            min_val = min(min_val, num);
            if (num % 2 != 0) {
                has_odd = true;
            }
        }

        // If the minimum element is odd, we can make all elements odd.
        if (min_val % 2 != 0) return true;

        // If minimum is even, we can only succeed if there are no odd numbers at all
        // (so all are already even). If an odd number exists, neither can the smallest
        // odd become even, nor can the smallest even become odd.
        return !has_odd;
    }
};