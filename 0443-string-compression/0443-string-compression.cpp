class Solution {
public:
    int compress(vector<char>& chars) {
        int write = 0;
        int read = 0;
        int n = chars.size();

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count occurrences of current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write character to array
            chars[write++] = currentChar;

            // Write count if greater than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};