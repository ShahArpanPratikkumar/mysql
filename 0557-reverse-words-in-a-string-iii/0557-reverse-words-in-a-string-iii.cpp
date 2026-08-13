class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int start = 0;
        
        for (int end = 0; end <= n; ++end) {
            // When we hit a space or end of the string, reverse the word
            if (end == n || s[end] == ' ') {
                int left = start;
                int right = end - 1;
                while (left < right) {
                    swap(s[left++], s[right--]);
                }
                start = end + 1; // Move start pointer to the next word
            }
        }
        
        return s;
    }
};