class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int last_end = -1;

        for (int center = 0; center < 2 * n - 1; ++center) {
            int left = center / 2;
            int right = left + (center % 2);

            while (left >= 0 && right < n && s[left] == s[right]) {
                if (left > last_end && (right - left + 1) >= k) {
                    count++;
                    last_end = right;
                    break;
                }
                left--;
                right++;
            }
        }

        return count;
    }
};